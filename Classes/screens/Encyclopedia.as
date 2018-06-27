package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Encyclopedia extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:Encyclopedia_mc;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var nowPage:int = 1;
        public var gotoPage:String = "";
        public var nowTarget:Object;
        public var oldEnemyPage:int = 1;
        public var oldEnemyTarget:String = "enemy1";
        public var oldTowerPage:int = 11;
        public var oldTowerTarget:String = "tower1";
        public var hint:Hint_mc;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function Encyclopedia()
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
            this.stage.frameRate = 60;
            if (!Main.mainClass.worldClass)
            {
                Main.mainClass.levelsMenuClass.manageListeners("off");
            }
            else
            {
                var _loc_2:* = 0;
                Main.mainClass.worldClass.y = 0;
                Main.mainClass.worldClass.x = _loc_2;
                var _loc_2:* = 0;
                Main.mainClass.worldClass.worldInterface.y = 0;
                Main.mainClass.worldClass.worldInterface.x = _loc_2;
                if (Main.mainClass.worldClass.towerMenu)
                {
                    Main.mainClass.worldClass.towerMenu.closeMenu(true);
                }
                else if (Main.mainClass.worldClass.ultraTowerMenu)
                {
                    Main.mainClass.worldClass.ultraTowerMenu.closeMenu(true);
                }
                Main.mainClass.worldClass.manageListeners("off");
                if (Main.mainClass.worldClass.exchange)
                {
                    Main.mainClass.worldClass.worldInterface.breaking();
                }
                else if (Main.mainClass.worldClass.getSphere || Main.mainClass.worldClass.cast)
                {
                    Main.mainClass.worldClass.manageMouse("show");
                }
            }
            this.container = new Encyclopedia_mc();
            this.container.stop();
            this.container.back.stop();
            this.container.back.backCase.setMouseEnabled(true);
            this.container.book.stop();
            this.container.book.btnEnemy.gotoAndStop(4);
            this.container.book.btnGuide.stop();
            this.container.book.btnTower.stop();
            this.container.book.btnEnemy.btnEnemyCase.setMouseEnabled(false);
            this.container.book.btnGuide.btnGuideCase.setMouseEnabled(true);
            this.container.book.btnTower.btnTowerCase.setMouseEnabled(true);
            var _loc_2:* = false;
            this.container.book.setMouseChildren(false);
            this.container.book.mouseEnabled = _loc_2;
            this.container.book.btnGuide.visible = false;
            this.addChild(this.container);
            this.boardManage(this.nowPage);
            this.targetManager(this.container.book.enemyPageLeft1.enemy1);
            this.container.book.enemyPageLeft1.btnLeft.visible = false;
            if (Main.mainClass.worldClass)
            {
                Main.mainClass.worldClass.manageIndexes();
            }
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
            if (this.openFlag)
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.openFlag = false;
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.stage.frameRate = 30;
                }
            }
            else if (this.closeFlag)
            {
                if (this.container.currentFrame > 1)
                {
                    this.container.gotoAndStop((this.container.currentFrame - 1));
                }
                else
                {
                    this.closeFlag = false;
                    this.kill();
                }
            }
            else if (this.gotoPage == "1-2")
            {
                if (this.container.book.currentFrame < 5)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame + 1));
                    if (this.container.book.currentFrame == 3)
                    {
                        if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[14] == 1)
                        {
                            this.contentManager("enemy1", -2);
                        }
                        else
                        {
                            this.contentManager("", -2);
                        }
                    }
                    else if (this.container.book.currentFrame == 4)
                    {
                        this.boardManage(-2);
                        if (this.container.book.enemyPageLeft2.enemy1.currentFrame == 1)
                        {
                            this.container.book.enemyPageLeft2.enemy1.gotoAndStop(2);
                        }
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(1);
                    this.nowPage = 2;
                    this.boardManage(this.nowPage);
                    if (this.container.book.enemyPageLeft1.enemy1.currentFrame != 3)
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy1);
                    }
                    else
                    {
                        this.nowTarget = null;
                        this.contentManager("", this.nowPage);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.gotoPage == "2-1")
            {
                if (this.container.book.currentFrame > 1)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame - 1));
                    if (this.container.book.currentFrame == 4)
                    {
                        this.boardManage(1);
                        if (this.container.book.enemyPageLeft1.enemy1.currentFrame == 1)
                        {
                            this.container.book.enemyPageLeft1.enemy1.gotoAndStop(2);
                        }
                    }
                    else if (this.container.book.currentFrame == 3)
                    {
                        if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[0] == 1)
                        {
                            this.contentManager("enemy1", 1);
                        }
                        else
                        {
                            this.contentManager("", 1);
                        }
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(1);
                    this.nowPage = 1;
                    this.boardManage(this.nowPage);
                    if (this.container.book.enemyPageLeft1.enemy1.currentFrame != 3)
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy1);
                    }
                    else
                    {
                        this.nowTarget = null;
                        this.contentManager("", this.nowPage);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.gotoPage == "00-10")
            {
                if (this.container.book.currentFrame < 9)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame + 1));
                    if (this.container.book.currentFrame == 7)
                    {
                        if (this.oldTowerPage == 13 && this.oldTowerTarget == "tower1")
                        {
                            if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[4] == 1)
                            {
                                this.contentManager("tower1", this.oldTowerPage);
                            }
                            else
                            {
                                this.contentManager("", this.oldTowerPage);
                            }
                        }
                        else
                        {
                            this.contentManager(this.oldTowerTarget, this.oldTowerPage);
                        }
                    }
                    else if (this.container.book.currentFrame == 8)
                    {
                        this.boardManage(this.oldTowerPage);
                        if (this.oldTowerTarget == "tower1")
                        {
                            if (this.container.book.towerPageLeft1.tower1.currentFrame == 1)
                            {
                                this.container.book.towerPageLeft1.tower1.gotoAndStop(2);
                            }
                        }
                        else if (this.oldTowerPage == "tower2")
                        {
                            this.container.book.towerPageLeft1.tower2.gotoAndStop(2);
                        }
                        else if (this.oldTowerPage == "tower3")
                        {
                            this.container.book.towerPageLeft1.tower3.gotoAndStop(2);
                        }
                        else if (this.oldTowerPage == "tower4")
                        {
                            this.container.book.towerPageLeft1.tower4.gotoAndStop(2);
                        }
                        else if (this.oldTowerPage == "tower5")
                        {
                            this.container.book.towerPageLeft1.tower5.gotoAndStop(2);
                        }
                        else if (this.oldTowerPage == "tower6")
                        {
                            this.container.book.towerPageLeft1.tower6.gotoAndStop(2);
                        }
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(9);
                    this.nowPage = this.oldTowerPage;
                    this.boardManage(this.nowPage);
                    if (this.oldTowerTarget == "tower1")
                    {
                        if (this.container.book.towerPageLeft1.tower1.currentFrame != 3)
                        {
                            this.targetManager(this.container.book.towerPageLeft1.tower1);
                        }
                        else
                        {
                            this.nowTarget = null;
                            this.contentManager("", this.nowPage);
                        }
                    }
                    else if (this.oldTowerTarget == "tower2")
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower2);
                    }
                    else if (this.oldTowerTarget == "tower3")
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower3);
                    }
                    else if (this.oldTowerTarget == "tower4")
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower4);
                    }
                    else if (this.oldTowerTarget == "tower5")
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower5);
                    }
                    else if (this.oldTowerTarget == "tower6")
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower6);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.gotoPage == "11-12")
            {
                if (this.container.book.currentFrame < 13)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame + 1));
                    if (this.container.book.currentFrame == 11)
                    {
                        if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[0] == 1)
                        {
                            this.contentManager("tower1", -12);
                        }
                        else
                        {
                            this.contentManager("", -12);
                        }
                    }
                    else if (this.container.book.currentFrame == 12)
                    {
                        this.boardManage(-12);
                        if (this.container.book.towerPageLeft2.tower1.currentFrame == 1)
                        {
                            this.container.book.towerPageLeft2.tower1.gotoAndStop(2);
                        }
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(9);
                    this.nowPage = 12;
                    this.boardManage(this.nowPage);
                    if (this.container.book.towerPageLeft1.tower1.currentFrame != 3)
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower1);
                    }
                    else
                    {
                        this.nowTarget = null;
                        this.contentManager("", this.nowPage);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.gotoPage == "12-13")
            {
                if (this.container.book.currentFrame < 13)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame + 1));
                    if (this.container.book.currentFrame == 11)
                    {
                        if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[4] == 1)
                        {
                            this.contentManager("tower1", -13);
                        }
                        else
                        {
                            this.contentManager("", -13);
                        }
                    }
                    else if (this.container.book.currentFrame == 12)
                    {
                        this.boardManage(-13);
                        if (this.container.book.towerPageLeft2.tower1.currentFrame == 1)
                        {
                            this.container.book.towerPageLeft2.tower1.gotoAndStop(2);
                        }
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(9);
                    this.nowPage = 13;
                    this.boardManage(this.nowPage);
                    if (this.container.book.towerPageLeft1.tower1.currentFrame != 3)
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower1);
                    }
                    else
                    {
                        this.nowTarget = null;
                        this.contentManager("", this.nowPage);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.gotoPage == "13-12")
            {
                if (this.container.book.currentFrame > 9)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame - 1));
                    if (this.container.book.currentFrame == 12)
                    {
                        this.boardManage(12);
                        if (this.container.book.towerPageLeft1.tower1.currentFrame == 1)
                        {
                            this.container.book.towerPageLeft1.tower1.gotoAndStop(2);
                        }
                    }
                    else if (this.container.book.currentFrame == 11)
                    {
                        if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[0])
                        {
                            this.contentManager("tower1", 12);
                        }
                        else
                        {
                            this.contentManager("", 12);
                        }
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(9);
                    this.nowPage = 12;
                    this.boardManage(this.nowPage);
                    if (this.container.book.towerPageLeft1.tower1.currentFrame != 3)
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower1);
                    }
                    else
                    {
                        this.nowTarget = null;
                        this.contentManager("", this.nowPage);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.gotoPage == "12-11")
            {
                if (this.container.book.currentFrame > 9)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame - 1));
                    if (this.container.book.currentFrame == 12)
                    {
                        this.boardManage(11);
                        if (this.container.book.towerPageLeft1.tower1.currentFrame == 1)
                        {
                            this.container.book.towerPageLeft1.tower1.gotoAndStop(2);
                        }
                    }
                    else if (this.container.book.currentFrame == 11)
                    {
                        this.contentManager("tower1", 11);
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(9);
                    this.nowPage = 11;
                    this.boardManage(this.nowPage);
                    if (this.container.book.towerPageLeft1.tower1.currentFrame != 3)
                    {
                        this.targetManager(this.container.book.towerPageLeft1.tower1);
                    }
                    else
                    {
                        this.nowTarget = null;
                        this.contentManager("", this.nowPage);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.gotoPage == "10-00")
            {
                if (this.container.book.currentFrame > 5)
                {
                    this.container.book.gotoAndStop((this.container.book.currentFrame - 1));
                    if (this.container.book.currentFrame == 8)
                    {
                        this.boardManage(-this.oldEnemyPage);
                        if (this.oldEnemyTarget == "enemy1")
                        {
                            if (this.container.book.enemyPageLeft2.enemy1.currentFrame == 1)
                            {
                                this.container.book.enemyPageLeft2.enemy1.gotoAndStop(2);
                            }
                        }
                        else if (this.oldEnemyTarget == "enemy2")
                        {
                            this.container.book.enemyPageLeft2.enemy2.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy3")
                        {
                            this.container.book.enemyPageLeft2.enemy3.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy4")
                        {
                            this.container.book.enemyPageLeft2.enemy4.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy5")
                        {
                            this.container.book.enemyPageLeft2.enemy5.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy6")
                        {
                            this.container.book.enemyPageLeft2.enemy6.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy7")
                        {
                            this.container.book.enemyPageLeft2.enemy7.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy8")
                        {
                            this.container.book.enemyPageLeft2.enemy8.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy9")
                        {
                            this.container.book.enemyPageLeft2.enemy9.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy10")
                        {
                            this.container.book.enemyPageLeft2.enemy10.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy11")
                        {
                            this.container.book.enemyPageLeft2.enemy11.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy12")
                        {
                            this.container.book.enemyPageLeft2.enemy12.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy13")
                        {
                            this.container.book.enemyPageLeft2.enemy13.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy14")
                        {
                            this.container.book.enemyPageLeft2.enemy14.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy15")
                        {
                            this.container.book.enemyPageLeft2.enemy15.gotoAndStop(2);
                        }
                        else if (this.oldEnemyTarget == "enemy16")
                        {
                            this.container.book.enemyPageLeft2.enemy16.gotoAndStop(2);
                        }
                    }
                    else if (this.container.book.currentFrame == 7)
                    {
                        if (this.oldEnemyPage == 1 && this.oldEnemyTarget == "enemy1")
                        {
                            if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[0] == 1)
                            {
                                this.contentManager("enemy1", -this.oldEnemyPage);
                            }
                            else
                            {
                                this.contentManager("", -this.oldEnemyPage);
                            }
                        }
                        else if (this.oldEnemyPage == 2 && this.oldEnemyTarget == "enemy1")
                        {
                            if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[16] == 1)
                            {
                                this.contentManager("enemy1", -this.oldEnemyPage);
                            }
                            else
                            {
                                this.contentManager("", -this.oldEnemyPage);
                            }
                        }
                        else
                        {
                            this.contentManager(this.oldEnemyTarget, -this.oldEnemyPage);
                        }
                    }
                }
                else
                {
                    this.gotoPage = "";
                    var _loc_2:* = true;
                    this.container.book.setMouseChildren(true);
                    this.container.book.mouseEnabled = _loc_2;
                    this.container.book.gotoAndStop(1);
                    this.nowPage = this.oldEnemyPage;
                    this.boardManage(this.nowPage);
                    if (this.oldEnemyTarget == "enemy1")
                    {
                        if (this.container.book.enemyPageLeft1.enemy1.currentFrame != 3)
                        {
                            this.targetManager(this.container.book.enemyPageLeft1.enemy1);
                        }
                        else
                        {
                            this.nowTarget = null;
                            this.contentManager("", this.nowPage);
                        }
                    }
                    else if (this.oldEnemyTarget == "enemy2")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy2);
                    }
                    else if (this.oldEnemyTarget == "enemy3")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy3);
                    }
                    else if (this.oldEnemyTarget == "enemy4")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy4);
                    }
                    else if (this.oldEnemyTarget == "enemy5")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy5);
                    }
                    else if (this.oldEnemyTarget == "enemy6")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy6);
                    }
                    else if (this.oldEnemyTarget == "enemy7")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy7);
                    }
                    else if (this.oldEnemyTarget == "enemy8")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy8);
                    }
                    else if (this.oldEnemyTarget == "enemy9")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy9);
                    }
                    else if (this.oldEnemyTarget == "enemy10")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy10);
                    }
                    else if (this.oldEnemyTarget == "enemy11")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy11);
                    }
                    else if (this.oldEnemyTarget == "enemy12")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy12);
                    }
                    else if (this.oldEnemyTarget == "enemy13")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy13);
                    }
                    else if (this.oldEnemyTarget == "enemy14")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy14);
                    }
                    else if (this.oldEnemyTarget == "enemy15")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy15);
                    }
                    else if (this.oldEnemyTarget == "enemy16")
                    {
                        this.targetManager(this.container.book.enemyPageLeft1.enemy16);
                    }
                    this.autoguidersButtons();
                }
            }
            else if (this.nowTarget)
            {
                if (this.nowPage < 11)
                {
                    if (this.nowTarget.cont.enemyCont.currentFrame < this.nowTarget.cont.enemyCont.totalFrames)
                    {
                        this.nowTarget.cont.enemyCont.gotoAndStop((this.nowTarget.cont.enemyCont.currentFrame + 1));
                    }
                    else
                    {
                        this.nowTarget.cont.enemyCont.gotoAndStop(1);
                    }
                    if (this.nowTarget.cont.currentFrame == 5 || this.nowTarget.cont.currentFrame == 10 || this.nowTarget.cont.currentFrame == 15)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 10)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 8 || this.nowTarget.cont.currentFrame == 13 || this.nowTarget.cont.currentFrame == 24)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 20)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 9 || this.nowTarget.cont.enemyCont.cont.currentFrame == 11 || this.nowTarget.cont.enemyCont.cont.currentFrame == 18 || this.nowTarget.cont.currentFrame == 25)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 30)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 19)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 35)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 26 || this.nowTarget.cont.currentFrame == 28)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 60)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 27)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 40)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 29)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 8)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 30)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < 10)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                    }
                    else if (this.nowTarget.cont.currentFrame == 35)
                    {
                        if (this.nowTarget.cont.enemyCont.cont.currentFrame < this.nowTarget.cont.enemyCont.cont.totalFrames)
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop((this.nowTarget.cont.enemyCont.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.enemyCont.cont.gotoAndStop(1);
                        }
                    }
                }
                else if (this.nowPage < 12)
                {
                    if (this.nowTarget.cont.towerCont)
                    {
                        if (this.nowTarget.cont.towerCont.currentFrame < this.nowTarget.cont.towerCont.totalFrames)
                        {
                            this.nowTarget.cont.towerCont.gotoAndStop((this.nowTarget.cont.towerCont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.towerCont.gotoAndStop(1);
                        }
                    }
                    else
                    {
                        if (this.nowTarget.cont.fire)
                        {
                            if (this.nowTarget.cont.fire.currentFrame < this.nowTarget.cont.fire.totalFrames)
                            {
                                this.nowTarget.cont.fire.gotoAndStop((this.nowTarget.cont.fire.currentFrame + 1));
                            }
                            else
                            {
                                this.nowTarget.cont.fire.gotoAndStop(1);
                            }
                        }
                        if (this.nowTarget.cont.ice)
                        {
                            if (this.nowTarget.cont.ice.currentFrame < this.nowTarget.cont.ice.totalFrames)
                            {
                                this.nowTarget.cont.ice.gotoAndStop((this.nowTarget.cont.ice.currentFrame + 1));
                            }
                            else
                            {
                                this.nowTarget.cont.ice.gotoAndStop(1);
                            }
                        }
                        if (this.nowTarget.cont.stone)
                        {
                            if (this.nowTarget.cont.stone.currentFrame < this.nowTarget.cont.stone.totalFrames)
                            {
                                this.nowTarget.cont.stone.gotoAndStop((this.nowTarget.cont.stone.currentFrame + 1));
                            }
                            else
                            {
                                this.nowTarget.cont.stone.gotoAndStop(1);
                            }
                        }
                        if (this.nowTarget.cont.levin)
                        {
                            if (this.nowTarget.cont.levin.currentFrame < this.nowTarget.cont.levin.totalFrames)
                            {
                                this.nowTarget.cont.levin.gotoAndStop((this.nowTarget.cont.levin.currentFrame + 1));
                            }
                            else
                            {
                                this.nowTarget.cont.levin.gotoAndStop(1);
                            }
                        }
                    }
                }
                else if (this.nowPage == 13)
                {
                    if (this.frameCounter % 2)
                    {
                        if (this.nowTarget.name != "tower3")
                        {
                            if (this.nowTarget.cont.towerCont.currentFrame < this.nowTarget.cont.towerCont.totalFrames)
                            {
                                this.nowTarget.cont.towerCont.gotoAndStop((this.nowTarget.cont.towerCont.currentFrame + 1));
                            }
                            else
                            {
                                this.nowTarget.cont.towerCont.gotoAndStop(1);
                            }
                        }
                        if (this.nowTarget.name == "tower4")
                        {
                            if (this.nowTarget.cont.towerCont.cont2.currentFrame < this.nowTarget.cont.towerCont.cont2.totalFrames)
                            {
                                this.nowTarget.cont.towerCont.cont2.gotoAndStop((this.nowTarget.cont.towerCont.cont2.currentFrame + 1));
                            }
                            else
                            {
                                this.nowTarget.cont.towerCont.cont2.gotoAndStop(1);
                            }
                        }
                    }
                    if (this.nowTarget.name == "tower3")
                    {
                        if (this.nowTarget.cont.towerCont.currentFrame < this.nowTarget.cont.towerCont.totalFrames)
                        {
                            this.nowTarget.cont.towerCont.gotoAndStop((this.nowTarget.cont.towerCont.currentFrame + 1));
                        }
                        else
                        {
                            this.nowTarget.cont.towerCont.gotoAndStop(1);
                        }
                    }
                    else if (this.nowTarget.name == "tower4")
                    {
                        this.nowTarget.cont.towerCont.cont2.rotation = this.nowTarget.cont.towerCont.cont2.rotation + 3;
                    }
                }
                else if (this.frameCounter % 2)
                {
                    if (this.nowTarget.cont.towerCont.currentFrame < this.nowTarget.cont.towerCont.totalFrames)
                    {
                        this.nowTarget.cont.towerCont.gotoAndStop((this.nowTarget.cont.towerCont.currentFrame + 1));
                    }
                    else
                    {
                        this.nowTarget.cont.towerCont.gotoAndStop(1);
                    }
                }
            }
            if (this.hint)
            {
                this.hint.x = this.mouseX;
                this.hint.y = this.mouseY;
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (this.gotoPage == "")
            {
                if (targetName == "backCase")
                {
                    if (this.container.back.currentFrame == 1)
                    {
                        this.container.back.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.container.back.currentFrame == 2)
                {
                    this.container.back.gotoAndStop(1);
                }
                if (targetName == "btnEnemyCase")
                {
                    if (this.container.book.btnEnemy.currentFrame == 1)
                    {
                        this.container.book.btnEnemy.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.container.book.btnEnemy.currentFrame == 2)
                {
                    this.container.book.btnEnemy.gotoAndStop(1);
                }
                if (targetName == "btnGuideCase")
                {
                    if (this.container.book.btnGuide.currentFrame == 1)
                    {
                        this.container.book.btnGuide.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.container.book.btnGuide.currentFrame == 2)
                {
                    this.container.book.btnGuide.gotoAndStop(1);
                }
                if (targetName == "btnTowerCase")
                {
                    if (this.container.book.btnTower.currentFrame == 1)
                    {
                        this.container.book.btnTower.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.container.book.btnTower.currentFrame == 2)
                {
                    this.container.book.btnTower.gotoAndStop(1);
                }
                if (targetName == "enemyCase")
                {
                    if (param1.target.parent.currentFrame == 1)
                    {
                        this.enemiesMouseMoveDefault();
                        param1.target.parent.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.nowPage < 11)
                {
                    this.enemiesMouseMoveDefault();
                }
                if (targetName == "towerCase")
                {
                    if (param1.target.parent.currentFrame == 1)
                    {
                        this.towersMouseMoveDefault();
                        param1.target.parent.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.nowPage > 10)
                {
                    this.towersMouseMoveDefault();
                }
                if (targetName == "arrowCase")
                {
                    if (param1.target.parent.currentFrame == 1)
                    {
                        if (event->target->getParent()->getName() == "btnLeft")
                        {
                            Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                        }
                        else if (event->target->getParent()->getName() == "btnRight")
                        {
                            Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                        }
                        param1.target.parent.gotoAndStop(2);
                    }
                }
                else if (this.container.book.enemyPageLeft1)
                {
                    if (this.container.book.enemyPageLeft1.btnLeft.currentFrame == 2)
                    {
                        this.container.book.enemyPageLeft1.btnLeft.gotoAndStop(1);
                    }
                    else if (this.container.book.enemyPageRight1.btnRight.currentFrame == 2)
                    {
                        this.container.book.enemyPageRight1.btnRight.gotoAndStop(1);
                    }
                }
                else if (this.container.book.towerPageLeft1)
                {
                    if (this.container.book.towerPageLeft1.btnLeft.currentFrame == 2)
                    {
                        this.container.book.towerPageLeft1.btnLeft.gotoAndStop(1);
                    }
                    else if (this.container.book.towerPageRight1.btnRight.currentFrame == 2)
                    {
                        this.container.book.towerPageRight1.btnRight.gotoAndStop(1);
                    }
                }
                if (targetName == "healthCase" || targetName == "speedCase" || targetName == "penaltyCase" || targetName == "fireResistCase" || targetName == "iceResistCase" || targetName == "stoneResistCase" || targetName == "levinResistCase" || targetName == "damageCase" || targetName == "castDamageCase" || targetName == "shootIntervalCase" || targetName == "radiusCase" || targetName == "addDamageCase")
                {
                    if (!this.hint)
                    {
                        this.hint = new Hint_mc();
                        this.hint.stop();
                        var _loc_2:* = false;
                        this.hint.setMouseChildren(false);
                        this.hint.mouseEnabled = _loc_2;
                        this.addChild(this.hint);
                    }
                    if (targetName == "healthCase")
                    {
                        this.hint.gotoAndStop(2);
                    }
                    else if (targetName == "speedCase")
                    {
                        this.hint.gotoAndStop(3);
                    }
                    else if (targetName == "penaltyCase")
                    {
                        this.hint.gotoAndStop(4);
                    }
                    else if (targetName == "fireResistCase")
                    {
                        this.hint.gotoAndStop(5);
                    }
                    else if (targetName == "iceResistCase")
                    {
                        this.hint.gotoAndStop(6);
                    }
                    else if (targetName == "stoneResistCase")
                    {
                        this.hint.gotoAndStop(7);
                    }
                    else if (targetName == "levinResistCase")
                    {
                        this.hint.gotoAndStop(8);
                    }
                    else if (targetName == "damageCase")
                    {
                        this.hint.gotoAndStop(9);
                    }
                    else if (targetName == "castDamageCase")
                    {
                        this.hint.gotoAndStop(10);
                    }
                    else if (targetName == "shootIntervalCase")
                    {
                        this.hint.gotoAndStop(11);
                    }
                    else if (targetName == "radiusCase")
                    {
                        this.hint.gotoAndStop(12);
                    }
                    else if (targetName == "addDamageCase")
                    {
                        this.hint.gotoAndStop(13);
                    }
                    this.hint.x = this.mouseX;
                    this.hint.y = this.mouseY;
                }
                else if (this.hint)
                {
                    this.removeChild(this.hint);
                    this.hint = null;
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (!this.openFlag && this.gotoPage == "")
            {
                if (event.target.name == "backCase")
                {
                    if (this.container.back.currentFrame == 2)
                    {
                        this.container.back.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "btnEnemyCase")
                {
                    if (this.container.book.btnEnemy.currentFrame == 2)
                    {
                        this.container.book.btnEnemy.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
                else if (event.target.name == "btnGuideCase")
                {
                    if (this.container.book.btnGuide.currentFrame == 2)
                    {
                        this.container.book.btnGuide.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "btnTowerCase")
                {
                    if (this.container.book.btnTower.currentFrame == 2)
                    {
                        this.container.book.btnTower.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
                else if (event.target.name == "enemyCase")
                {
                    if (event.target.parent.currentFrame == 2 && event.target.parent != this.nowTarget)
                    {
                        this.targetManager(event.target.parent);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "towerCase")
                {
                    if (event.target.parent.currentFrame == 2 && event.target.parent != this.nowTarget)
                    {
                        this.targetManager(event.target.parent);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "arrowCase")
                {
                    if (event.target.parent.currentFrame == 2)
                    {
                        if (event.target.parent.name == "btnLeft")
                        {
                            Sounds.instance.playSound("snd_menu_pageScrolling");
                        }
                        else if (event.target.parent.name == "btnRight")
                        {
                            Sounds.instance.playSound("snd_menu_pageScrolling");
                        }
                        event.target.parent.gotoAndStop(3);
                    }
                }
                else if (event.target.name == "shadow")
                {
                    this.close();
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (this.gotoPage == "")
            {
                if (event.target.name == "backCase")
                {
                    if (this.container.back.currentFrame == 3)
                    {
                        this.container.back.gotoAndStop(2);
                        this.close();
                    }
                }
                else if (this.container.back.currentFrame == 3)
                {
                    this.container.back.gotoAndStop(1);
                }
                if (event.target.name == "btnEnemyCase")
                {
                    if (this.container.book.btnEnemy.currentFrame == 3)
                    {
                        this.container.book.btnEnemy.gotoAndStop(4);
                        this.container.book.btnTower.gotoAndStop(1);
                        this.container.book.btnEnemy.btnEnemyCase.setMouseEnabled(false);
                        this.container.book.btnTower.btnTowerCase.setMouseEnabled(true);
                        this.gotoPage = "10-00";
                        this.oldTowerPage = this.nowPage;
                        if (this.nowTarget)
                        {
                            this.oldTowerTarget = this.nowTarget.name;
                        }
                        if (this.nowTarget)
                        {
                            this.tempObject = new Object();
                            this.tempObject.name = this.nowTarget.name;
                            if (this.nowTarget.cont.towerCont)
                            {
                                this.tempObject.saveFrame = this.nowTarget.cont.towerCont.currentFrame;
                            }
                            else
                            {
                                if (this.nowTarget.cont.fire)
                                {
                                    this.tempObject.saveFrameFire = this.nowTarget.cont.fire.currentFrame;
                                }
                                if (this.nowTarget.cont.ice)
                                {
                                    this.tempObject.saveFrameIce = this.nowTarget.cont.ice.currentFrame;
                                }
                                if (this.nowTarget.cont.stone)
                                {
                                    this.tempObject.saveFrameStone = this.nowTarget.cont.stone.currentFrame;
                                }
                                if (this.nowTarget.cont.levin)
                                {
                                    this.tempObject.saveFrameLevin = this.nowTarget.cont.levin.currentFrame;
                                }
                            }
                            this.nowTarget = this.tempObject;
                        }
                        this.container.book.gotoAndStop(9);
                        this.boardManage(this.nowPage);
                        if (this.nowTarget)
                        {
                            if (this.nowTarget.name == "tower1")
                            {
                                this.container.book.towerPageLeft1.tower1.gotoAndStop(2);
                                this.container.book.towerPageLeft1.tower1.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "tower2")
                            {
                                this.container.book.towerPageLeft1.tower2.gotoAndStop(2);
                                this.container.book.towerPageLeft1.tower2.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "tower3")
                            {
                                this.container.book.towerPageLeft1.tower3.gotoAndStop(2);
                                this.container.book.towerPageLeft1.tower3.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "tower4")
                            {
                                this.container.book.towerPageLeft1.tower4.gotoAndStop(2);
                                this.container.book.towerPageLeft1.tower4.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "tower5")
                            {
                                this.container.book.towerPageLeft1.tower5.gotoAndStop(2);
                                if (this.container.book.towerPageLeft1.tower5.cont.towerCont)
                                {
                                    this.container.book.towerPageLeft1.tower5.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                }
                                else
                                {
                                    if (this.container.book.towerPageLeft1.tower5.cont.fire)
                                    {
                                        this.container.book.towerPageLeft1.tower5.cont.fire.gotoAndStop(this.nowTarget.saveFrameFire);
                                    }
                                    if (this.container.book.towerPageLeft1.tower5.cont.ice)
                                    {
                                        this.container.book.towerPageLeft1.tower5.cont.ice.gotoAndStop(this.nowTarget.saveFrameIce);
                                    }
                                    if (this.container.book.towerPageLeft1.tower5.cont.stone)
                                    {
                                        this.container.book.towerPageLeft1.tower5.cont.stone.gotoAndStop(this.nowTarget.saveFrameStone);
                                    }
                                    if (this.container.book.towerPageLeft1.tower5.cont.levin)
                                    {
                                        this.container.book.towerPageLeft1.tower5.cont.levin.gotoAndStop(this.nowTarget.saveFrameLevin);
                                    }
                                }
                            }
                            else if (this.nowTarget.name == "tower6")
                            {
                                this.container.book.towerPageLeft1.tower6.gotoAndStop(2);
                                if (this.container.book.towerPageLeft1.tower6.cont.towerCont)
                                {
                                    this.container.book.towerPageLeft1.tower6.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                }
                                else
                                {
                                    if (this.container.book.towerPageLeft1.tower6.cont.fire)
                                    {
                                        this.container.book.towerPageLeft1.tower6.cont.fire.gotoAndStop(this.nowTarget.saveFrameFire);
                                    }
                                    if (this.container.book.towerPageLeft1.tower6.cont.ice)
                                    {
                                        this.container.book.towerPageLeft1.tower6.cont.ice.gotoAndStop(this.nowTarget.saveFrameIce);
                                    }
                                    if (this.container.book.towerPageLeft1.tower6.cont.stone)
                                    {
                                        this.container.book.towerPageLeft1.tower6.cont.stone.gotoAndStop(this.nowTarget.saveFrameStone);
                                    }
                                    if (this.container.book.towerPageLeft1.tower6.cont.levin)
                                    {
                                        this.container.book.towerPageLeft1.tower6.cont.levin.gotoAndStop(this.nowTarget.saveFrameLevin);
                                    }
                                }
                            }
                            this.contentManager(this.nowTarget.name, this.nowPage);
                        }
                        else
                        {
                            this.contentManager("", this.nowPage);
                        }
                        var _loc_2:* = false;
                        this.container.book.setMouseChildren(false);
                        this.container.book.mouseEnabled = _loc_2;
                        this.nowTarget = null;
                    }
                }
                else if (this.container.book.btnEnemy.currentFrame == 3)
                {
                    this.container.book.btnEnemy.gotoAndStop(1);
                }
                if (event.target.name == "btnGuideCase")
                {
                    if (this.container.book.btnGuide.currentFrame == 3)
                    {
                        this.container.book.btnGuide.gotoAndStop(2);
                    }
                }
                else if (this.container.book.btnGuide.currentFrame == 3)
                {
                    this.container.book.btnGuide.gotoAndStop(1);
                }
                if (event.target.name == "btnTowerCase")
                {
                    if (this.container.book.btnTower.currentFrame == 3)
                    {
                        this.container.book.btnTower.gotoAndStop(4);
                        this.container.book.btnEnemy.gotoAndStop(1);
                        this.container.book.btnEnemy.btnEnemyCase.setMouseEnabled(true);
                        this.container.book.btnTower.btnTowerCase.setMouseEnabled(false);
                        this.gotoPage = "00-10";
                        this.oldEnemyPage = this.nowPage;
                        if (this.nowTarget)
                        {
                            this.oldEnemyTarget = this.nowTarget.name;
                        }
                        if (this.nowTarget)
                        {
                            this.tempObject = new Object();
                            this.tempObject.name = this.nowTarget.name;
                            this.tempObject.saveFrame = this.nowTarget.cont.enemyCont.currentFrame;
                            this.nowTarget = this.tempObject;
                        }
                        this.container.book.gotoAndStop(5);
                        this.boardManage(-this.nowPage);
                        if (this.nowTarget)
                        {
                            if (this.nowTarget.name == "enemy1")
                            {
                                this.container.book.enemyPageLeft2.enemy1.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy1.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy2")
                            {
                                this.container.book.enemyPageLeft2.enemy2.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy2.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy3")
                            {
                                this.container.book.enemyPageLeft2.enemy3.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy3.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy4")
                            {
                                this.container.book.enemyPageLeft2.enemy4.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy4.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy5")
                            {
                                this.container.book.enemyPageLeft2.enemy5.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy5.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy6")
                            {
                                this.container.book.enemyPageLeft2.enemy6.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy6.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy7")
                            {
                                this.container.book.enemyPageLeft2.enemy7.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy7.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy8")
                            {
                                this.container.book.enemyPageLeft2.enemy8.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy8.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy9")
                            {
                                this.container.book.enemyPageLeft2.enemy9.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy9.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy10")
                            {
                                this.container.book.enemyPageLeft2.enemy10.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy10.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy11")
                            {
                                this.container.book.enemyPageLeft2.enemy11.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy11.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy12")
                            {
                                this.container.book.enemyPageLeft2.enemy12.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy12.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy13")
                            {
                                this.container.book.enemyPageLeft2.enemy13.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy13.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy14")
                            {
                                this.container.book.enemyPageLeft2.enemy14.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy14.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy15")
                            {
                                this.container.book.enemyPageLeft2.enemy15.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy15.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            else if (this.nowTarget.name == "enemy16")
                            {
                                this.container.book.enemyPageLeft2.enemy16.gotoAndStop(2);
                                this.container.book.enemyPageLeft2.enemy16.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                            }
                            this.contentManager(this.nowTarget.name, -this.nowPage);
                        }
                        else
                        {
                            this.contentManager("", -this.nowPage);
                        }
                        var _loc_2:* = false;
                        this.container.book.setMouseChildren(false);
                        this.container.book.mouseEnabled = _loc_2;
                        this.nowTarget = null;
                    }
                }
                else if (this.container.book.btnTower.currentFrame == 3)
                {
                    this.container.book.btnTower.gotoAndStop(1);
                }
                if (event.target.name == "arrowCase")
                {
                    if (event.target.parent.currentFrame == 3)
                    {
                        event.target.parent.gotoAndStop(2);
                        if (event.target.parent.name == "btnLeft")
                        {
                            if (this.nowPage == 2)
                            {
                                this.gotoPage = "2-1";
                                if (this.nowTarget)
                                {
                                    this.tempObject = new Object();
                                    this.tempObject.name = this.nowTarget.name;
                                    this.tempObject.saveFrame = this.nowTarget.cont.enemyCont.currentFrame;
                                    this.nowTarget = this.tempObject;
                                }
                                this.container.book.gotoAndStop(5);
                                this.boardManage(-2);
                                if (this.nowTarget)
                                {
                                    if (this.nowTarget.name == "enemy1")
                                    {
                                        this.container.book.enemyPageLeft2.enemy1.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy1.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy2")
                                    {
                                        this.container.book.enemyPageLeft2.enemy2.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy2.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy3")
                                    {
                                        this.container.book.enemyPageLeft2.enemy3.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy3.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy4")
                                    {
                                        this.container.book.enemyPageLeft2.enemy4.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy4.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy5")
                                    {
                                        this.container.book.enemyPageLeft2.enemy5.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy5.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy6")
                                    {
                                        this.container.book.enemyPageLeft2.enemy6.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy6.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy7")
                                    {
                                        this.container.book.enemyPageLeft2.enemy7.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy7.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy8")
                                    {
                                        this.container.book.enemyPageLeft2.enemy8.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy8.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy9")
                                    {
                                        this.container.book.enemyPageLeft2.enemy9.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy9.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy10")
                                    {
                                        this.container.book.enemyPageLeft2.enemy10.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy10.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy11")
                                    {
                                        this.container.book.enemyPageLeft2.enemy11.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy11.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy12")
                                    {
                                        this.container.book.enemyPageLeft2.enemy12.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy12.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy13")
                                    {
                                        this.container.book.enemyPageLeft2.enemy13.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy13.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy14")
                                    {
                                        this.container.book.enemyPageLeft2.enemy14.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy14.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy15")
                                    {
                                        this.container.book.enemyPageLeft2.enemy15.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy15.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "enemy16")
                                    {
                                        this.container.book.enemyPageLeft2.enemy16.gotoAndStop(2);
                                        this.container.book.enemyPageLeft2.enemy16.cont.enemyCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    this.contentManager(this.nowTarget.name, -2);
                                }
                                else
                                {
                                    this.contentManager("", -2);
                                }
                            }
                            else if (this.nowPage == 12)
                            {
                                this.gotoPage = "12-11";
                                if (this.nowTarget)
                                {
                                    this.tempObject = new Object();
                                    this.tempObject.name = this.nowTarget.name;
                                    this.tempObject.saveFrame = this.nowTarget.cont.towerCont.currentFrame;
                                    this.nowTarget = this.tempObject;
                                }
                                this.container.book.gotoAndStop(13);
                                this.boardManage(-12);
                                if (this.nowTarget)
                                {
                                    if (this.nowTarget.name == "tower1")
                                    {
                                        this.container.book.towerPageLeft2.tower1.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower1.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "tower2")
                                    {
                                        this.container.book.towerPageLeft2.tower2.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower2.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "tower3")
                                    {
                                        this.container.book.towerPageLeft2.tower3.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower3.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "tower4")
                                    {
                                        this.container.book.towerPageLeft2.tower4.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower4.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    this.contentManager(this.nowTarget.name, -12);
                                }
                                else
                                {
                                    this.contentManager("", -12);
                                }
                            }
                            else if (this.nowPage == 13)
                            {
                                this.gotoPage = "13-12";
                                if (this.nowTarget)
                                {
                                    this.tempObject = new Object();
                                    this.tempObject.name = this.nowTarget.name;
                                    this.tempObject.saveFrame = this.nowTarget.cont.towerCont.currentFrame;
                                    this.nowTarget = this.tempObject;
                                }
                                this.container.book.gotoAndStop(13);
                                this.boardManage(-13);
                                if (this.nowTarget)
                                {
                                    if (this.nowTarget.name == "tower1")
                                    {
                                        this.container.book.towerPageLeft2.tower1.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower1.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "tower2")
                                    {
                                        this.container.book.towerPageLeft2.tower2.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower2.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "tower3")
                                    {
                                        this.container.book.towerPageLeft2.tower3.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower3.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    else if (this.nowTarget.name == "tower4")
                                    {
                                        this.container.book.towerPageLeft2.tower4.gotoAndStop(2);
                                        this.container.book.towerPageLeft2.tower4.cont.towerCont.gotoAndStop(this.nowTarget.saveFrame);
                                    }
                                    this.contentManager(this.nowTarget.name, -13);
                                }
                                else
                                {
                                    this.contentManager("", -13);
                                }
                            }
                        }
                        else if (event.target.parent.name == "btnRight")
                        {
                            if (this.nowPage == 1)
                            {
                                this.gotoPage = "1-2";
                            }
                            else if (this.nowPage == 11)
                            {
                                this.gotoPage = "11-12";
                            }
                            else if (this.nowPage == 12)
                            {
                                this.gotoPage = "12-13";
                            }
                        }
                        var _loc_2:* = false;
                        this.container.book.setMouseChildren(false);
                        this.container.book.mouseEnabled = _loc_2;
                        this.nowTarget = null;
                    }
                }
                else if (this.container.book.enemyPageLeft1)
                {
                    if (this.container.book.enemyPageLeft1.btnLeft.currentFrame == 3)
                    {
                        this.container.book.enemyPageLeft1.btnLeft.gotoAndStop(1);
                    }
                    else if (this.container.book.enemyPageRight1.btnRight.currentFrame == 3)
                    {
                        this.container.book.enemyPageRight1.btnRight.gotoAndStop(1);
                    }
                }
                else if (this.container.book.towerPageLeft1)
                {
                    if (this.container.book.towerPageLeft1.btnLeft.currentFrame == 3)
                    {
                        this.container.book.towerPageLeft1.btnLeft.gotoAndStop(1);
                    }
                    else if (this.container.book.towerPageRight1.btnRight.currentFrame == 3)
                    {
                        this.container.book.towerPageRight1.btnRight.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        public function pageStop() : void
        {
            if (this.container.book.enemyPageLeft1)
            {
                this.enemyPageLeftManage(this.container.book.enemyPageLeft1);
            }
            if (this.container.book.enemyPageLeft2)
            {
                this.enemyPageLeftManage(this.container.book.enemyPageLeft2);
            }
            if (this.container.book.enemyPageRight1)
            {
                this.enemyPageRightManage(this.container.book.enemyPageRight1);
            }
            if (this.container.book.enemyPageRight2)
            {
                this.enemyPageRightManage(this.container.book.enemyPageRight2);
            }
            if (this.container.book.towerPageLeft1)
            {
                this.towerPageLeftManage(this.container.book.towerPageLeft1);
            }
            if (this.container.book.towerPageLeft2)
            {
                this.towerPageLeftManage(this.container.book.towerPageLeft2);
            }
            if (this.container.book.towerPageRight1)
            {
                this.towerPageRightManage(this.container.book.towerPageRight1);
            }
            if (this.container.book.towerPageRight2)
            {
                this.towerPageRightManage(this.container.book.towerPageRight2);
            }
            return;
        }// end function

        public function enemyPageLeftManage(param1:Object) : void
        {
            param1.stop();
            param1.enemy1.stop();
            param1.enemy2.stop();
            param1.enemy3.stop();
            param1.enemy4.stop();
            param1.enemy5.stop();
            param1.enemy6.stop();
            param1.enemy7.stop();
            param1.enemy8.stop();
            param1.enemy9.stop();
            param1.enemy10.stop();
            param1.enemy11.stop();
            param1.enemy12.stop();
            param1.enemy13.stop();
            param1.enemy14.stop();
            param1.enemy15.stop();
            param1.enemy16.stop();
            if (param1.enemy1.cont)
            {
                param1.enemy1.cont.stop();
                param1.enemy1.cont.enemyCont.stop();
                param1.enemy1.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy1)
                {
                    param1.enemy1.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy1.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy2.cont)
            {
                param1.enemy2.cont.stop();
                param1.enemy2.cont.enemyCont.stop();
                param1.enemy2.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy2)
                {
                    param1.enemy2.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy2.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy3.cont)
            {
                param1.enemy3.cont.stop();
                param1.enemy3.cont.enemyCont.stop();
                param1.enemy3.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy3)
                {
                    param1.enemy3.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy3.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy4.cont)
            {
                param1.enemy4.cont.stop();
                param1.enemy4.cont.enemyCont.stop();
                param1.enemy4.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy4)
                {
                    param1.enemy4.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy4.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy5.cont)
            {
                param1.enemy5.cont.stop();
                param1.enemy5.cont.enemyCont.stop();
                param1.enemy5.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy5)
                {
                    param1.enemy5.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy5.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy6.cont)
            {
                param1.enemy6.cont.stop();
                param1.enemy6.cont.enemyCont.stop();
                param1.enemy6.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy6)
                {
                    param1.enemy6.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy6.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy7.cont)
            {
                param1.enemy7.cont.stop();
                param1.enemy7.cont.enemyCont.stop();
                param1.enemy7.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy7)
                {
                    param1.enemy7.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy7.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy8.cont)
            {
                param1.enemy8.cont.stop();
                param1.enemy8.cont.enemyCont.stop();
                param1.enemy8.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy8)
                {
                    param1.enemy8.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy8.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy9.cont)
            {
                param1.enemy9.cont.stop();
                param1.enemy9.cont.enemyCont.stop();
                param1.enemy9.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy9)
                {
                    param1.enemy9.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy9.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy10.cont)
            {
                param1.enemy10.cont.stop();
                param1.enemy10.cont.enemyCont.stop();
                param1.enemy10.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy10)
                {
                    param1.enemy10.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy10.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy11.cont)
            {
                param1.enemy11.cont.stop();
                param1.enemy11.cont.enemyCont.stop();
                param1.enemy11.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy11)
                {
                    param1.enemy11.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy11.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy12.cont)
            {
                param1.enemy12.cont.stop();
                param1.enemy12.cont.enemyCont.stop();
                param1.enemy12.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy12)
                {
                    param1.enemy12.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy12.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy13.cont)
            {
                param1.enemy13.cont.stop();
                param1.enemy13.cont.enemyCont.stop();
                param1.enemy13.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy13)
                {
                    param1.enemy13.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy13.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy14.cont)
            {
                param1.enemy14.cont.stop();
                param1.enemy14.cont.enemyCont.stop();
                param1.enemy14.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy14)
                {
                    param1.enemy14.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy14.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy15.cont)
            {
                param1.enemy15.cont.stop();
                param1.enemy15.cont.enemyCont.stop();
                param1.enemy15.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy15)
                {
                    param1.enemy15.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy15.enemyCase.setMouseEnabled(false);
                }
            }
            if (param1.enemy16.cont)
            {
                param1.enemy16.cont.stop();
                param1.enemy16.cont.enemyCont.stop();
                param1.enemy16.cont.enemyCont.cont.stop();
                if (this.nowTarget != param1.enemy16)
                {
                    param1.enemy16.enemyCase.setMouseEnabled(true);
                }
                else
                {
                    param1.enemy16.enemyCase.setMouseEnabled(false);
                }
            }
            param1.btnLeft.stop();
            param1.btnLeft.arrowCase.setMouseEnabled(true);
            return;
        }// end function

        public function enemyPageRightManage(param1:Object) : void
        {
            param1.stop();
            if (param1.icons)
            {
                param1.icons.stop();
            }
            param1.btnRight.stop();
            param1.btnRight.arrowCase.setMouseEnabled(true);
            return;
        }// end function

        public function towerPageLeftManage(param1:Object) : void
        {
            param1.stop();
            param1.tower1.stop();
            param1.tower2.stop();
            param1.tower3.stop();
            param1.tower4.stop();
            if (param1.tower1.cont)
            {
                param1.tower1.cont.stop();
                param1.tower1.cont.towerCont.stop();
                if (this.nowTarget != param1.tower1)
                {
                    param1.tower1.towerCase.setMouseEnabled(true);
                }
                else
                {
                    param1.tower1.towerCase.setMouseEnabled(false);
                }
            }
            if (param1.tower2.cont)
            {
                param1.tower2.cont.stop();
                param1.tower2.cont.towerCont.stop();
                if (this.nowTarget != param1.tower2)
                {
                    param1.tower2.towerCase.setMouseEnabled(true);
                }
                else
                {
                    param1.tower2.towerCase.setMouseEnabled(false);
                }
            }
            if (param1.tower3.cont)
            {
                param1.tower3.cont.stop();
                param1.tower3.cont.towerCont.stop();
                if (this.nowTarget != param1.tower3)
                {
                    param1.tower3.towerCase.setMouseEnabled(true);
                }
                else
                {
                    param1.tower3.towerCase.setMouseEnabled(false);
                }
            }
            if (param1.tower4.cont)
            {
                param1.tower4.cont.stop();
                param1.tower4.cont.towerCont.stop();
                if (this.nowTarget != param1.tower4)
                {
                    param1.tower4.towerCase.setMouseEnabled(true);
                }
                else
                {
                    param1.tower4.towerCase.setMouseEnabled(false);
                }
            }
            if (param1.tower5)
            {
                param1.tower5.stop();
                param1.tower6.stop();
                if (param1.tower5.cont)
                {
                    param1.tower5.cont.stop();
                    if (param1.tower5.cont.towerCont)
                    {
                        param1.tower5.cont.towerCont.stop();
                    }
                    else
                    {
                        if (param1.tower5.cont.fire)
                        {
                            param1.tower5.cont.fire.stop();
                        }
                        if (param1.tower5.cont.ice)
                        {
                            param1.tower5.cont.ice.stop();
                        }
                        if (param1.tower5.cont.stone)
                        {
                            param1.tower5.cont.stone.stop();
                        }
                        if (param1.tower5.cont.levin)
                        {
                            param1.tower5.cont.levin.stop();
                        }
                    }
                    param1.tower5.towerCase.setMouseEnabled(true);
                }
                if (param1.tower6.cont)
                {
                    param1.tower6.cont.stop();
                    if (param1.tower6.cont.towerCont)
                    {
                        param1.tower6.cont.towerCont.stop();
                    }
                    else
                    {
                        if (param1.tower6.cont.fire)
                        {
                            param1.tower6.cont.fire.stop();
                        }
                        if (param1.tower6.cont.ice)
                        {
                            param1.tower6.cont.ice.stop();
                        }
                        if (param1.tower6.cont.stone)
                        {
                            param1.tower6.cont.stone.stop();
                        }
                        if (param1.tower6.cont.levin)
                        {
                            param1.tower6.cont.levin.stop();
                        }
                    }
                    param1.tower6.towerCase.setMouseEnabled(true);
                }
            }
            param1.btnLeft.stop();
            param1.btnLeft.arrowCase.setMouseEnabled(true);
            return;
        }// end function

        public function towerPageRightManage(param1:Object) : void
        {
            param1.stop();
            param1.btnRight.stop();
            param1.btnRight.setMouseEnabled(true);
            return;
        }// end function

        public function targetManager(param1:MovieClip) : void
        {
            if (this.nowTarget)
            {
                this.nowTarget.gotoAndStop(1);
                if (this.nowTarget.enemyCase)
                {
                    this.nowTarget.enemyCase.setMouseEnabled(true);
                }
                else if (this.nowTarget.towerCase)
                {
                    this.nowTarget.towerCase.setMouseEnabled(true);
                }
            }
            this.nowTarget = param1;
            this.nowTarget.gotoAndStop(2);
            if (this.nowPage == 13)
            {
                if (this.nowTarget.name == "tower4")
                {
                    this.nowTarget.cont.towerCont.cont2.stop();
                }
            }
            this.contentManager(this.nowTarget.name, this.nowPage);
            return;
        }// end function

        public function contentManager(param1:String, param2:int) : void
        {
            if (param2 == 1 || param2 == -1)
            {
                if (param2 == 1)
                {
                    this.tempObject = this.container.book.enemyPageRight1;
                }
                else
                {
                    this.tempObject = this.container.book.enemyPageRight2;
                }
                this.tempObject.gotoAndStop(1);
                if (param1 == "enemy1")
                {
                    this.tempObject.icons.gotoAndStop(3);
                    this.tempObject.note.gotoAndStop(1);
                    this.tempObject1 = Encyclopedia.enemyInfo(1);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy2")
                {
                    this.tempObject.icons.gotoAndStop(4);
                    this.tempObject.note.gotoAndStop(2);
                    this.tempObject1 = Encyclopedia.enemyInfo(2);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy3")
                {
                    this.tempObject.icons.gotoAndStop(5);
                    this.tempObject.note.gotoAndStop(3);
                    this.tempObject1 = Encyclopedia.enemyInfo(3);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy4")
                {
                    this.tempObject.icons.gotoAndStop(6);
                    this.tempObject.note.gotoAndStop(4);
                    this.tempObject1 = Encyclopedia.enemyInfo(4);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy5")
                {
                    this.tempObject.icons.gotoAndStop(7);
                    this.tempObject.note.gotoAndStop(5);
                    this.tempObject1 = Encyclopedia.enemyInfo(5);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy6")
                {
                    this.tempObject.icons.gotoAndStop(8);
                    this.tempObject.note.gotoAndStop(6);
                    this.tempObject1 = Encyclopedia.enemyInfo(6);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy7")
                {
                    this.tempObject.icons.gotoAndStop(9);
                    this.tempObject.note.gotoAndStop(7);
                    this.tempObject1 = Encyclopedia.enemyInfo(7);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy8")
                {
                    this.tempObject.icons.gotoAndStop(10);
                    this.tempObject.note.gotoAndStop(8);
                    this.tempObject1 = Encyclopedia.enemyInfo(8);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy9")
                {
                    this.tempObject.icons.gotoAndStop(11);
                    this.tempObject.note.gotoAndStop(9);
                    this.tempObject1 = Encyclopedia.enemyInfo(9);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy10")
                {
                    this.tempObject.icons.gotoAndStop(12);
                    this.tempObject.note.gotoAndStop(10);
                    this.tempObject1 = Encyclopedia.enemyInfo(10);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy11")
                {
                    this.tempObject.icons.gotoAndStop(13);
                    this.tempObject.note.gotoAndStop(11);
                    this.tempObject1 = Encyclopedia.enemyInfo(11);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy12")
                {
                    this.tempObject.icons.gotoAndStop(14);
                    this.tempObject.note.gotoAndStop(12);
                    this.tempObject1 = Encyclopedia.enemyInfo(12);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy13")
                {
                    this.tempObject.icons.gotoAndStop(15);
                    this.tempObject.note.gotoAndStop(13);
                    this.tempObject1 = Encyclopedia.enemyInfo(13);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy14")
                {
                    this.tempObject.icons.gotoAndStop(16);
                    this.tempObject.note.gotoAndStop(14);
                    this.tempObject1 = Encyclopedia.enemyInfo(14);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy15")
                {
                    this.tempObject.icons.gotoAndStop(17);
                    this.tempObject.note.gotoAndStop(15);
                    this.tempObject1 = Encyclopedia.enemyInfo(15);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy16")
                {
                    this.tempObject.icons.gotoAndStop(18);
                    this.tempObject.note.gotoAndStop(16);
                    this.tempObject1 = Encyclopedia.enemyInfo(16);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else
                {
                    this.tempObject.gotoAndStop(2);
                }
            }
            else if (param2 == 2 || param2 == -2)
            {
                if (param2 == 2)
                {
                    this.tempObject = this.container.book.enemyPageRight1;
                }
                else
                {
                    this.tempObject = this.container.book.enemyPageRight2;
                }
                this.tempObject.gotoAndStop(1);
                if (param1 == "enemy1")
                {
                    this.tempObject.icons.gotoAndStop(19);
                    this.tempObject.note.gotoAndStop(17);
                    this.tempObject1 = Encyclopedia.enemyInfo(17);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy2")
                {
                    this.tempObject.icons.gotoAndStop(20);
                    this.tempObject.note.gotoAndStop(18);
                    this.tempObject1 = Encyclopedia.enemyInfo(18);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy3")
                {
                    this.tempObject.icons.gotoAndStop(21);
                    this.tempObject.note.gotoAndStop(19);
                    this.tempObject1 = Encyclopedia.enemyInfo(19);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy4")
                {
                    this.tempObject.icons.gotoAndStop(22);
                    this.tempObject.note.gotoAndStop(20);
                    this.tempObject1 = Encyclopedia.enemyInfo(20);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy5")
                {
                    this.tempObject.icons.gotoAndStop(23);
                    this.tempObject.note.gotoAndStop(21);
                    this.tempObject1 = Encyclopedia.enemyInfo(21);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy6")
                {
                    this.tempObject.icons.gotoAndStop(24);
                    this.tempObject.note.gotoAndStop(22);
                    this.tempObject1 = Encyclopedia.enemyInfo(22);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy7")
                {
                    this.tempObject.icons.gotoAndStop(25);
                    this.tempObject.note.gotoAndStop(23);
                    this.tempObject1 = Encyclopedia.enemyInfo(23);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy8")
                {
                    this.tempObject.icons.gotoAndStop(26);
                    this.tempObject.note.gotoAndStop(24);
                    this.tempObject1 = Encyclopedia.enemyInfo(24);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy9")
                {
                    this.tempObject.icons.gotoAndStop(27);
                    this.tempObject.note.gotoAndStop(25);
                    this.tempObject1 = Encyclopedia.enemyInfo(25);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy10")
                {
                    this.tempObject.icons.gotoAndStop(28);
                    this.tempObject.note.gotoAndStop(26);
                    this.tempObject1 = Encyclopedia.enemyInfo(26);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy11")
                {
                    this.tempObject.icons.gotoAndStop(29);
                    this.tempObject.note.gotoAndStop(27);
                    this.tempObject1 = Encyclopedia.enemyInfo(27);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy12")
                {
                    this.tempObject.icons.gotoAndStop(30);
                    this.tempObject.note.gotoAndStop(28);
                    this.tempObject1 = Encyclopedia.enemyInfo(28);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy13")
                {
                    this.tempObject.icons.gotoAndStop(31);
                    this.tempObject.note.gotoAndStop(29);
                    this.tempObject1 = Encyclopedia.enemyInfo(29);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy14")
                {
                    this.tempObject.icons.gotoAndStop(32);
                    this.tempObject.note.gotoAndStop(30);
                    this.tempObject1 = Encyclopedia.enemyInfo(30);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy15")
                {
                    this.tempObject.icons.gotoAndStop(33);
                    this.tempObject.note.gotoAndStop(31);
                    this.tempObject1 = Encyclopedia.enemyInfo(31);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else if (param1 == "enemy16")
                {
                    this.tempObject.icons.gotoAndStop(34);
                    this.tempObject.note.gotoAndStop(32);
                    this.tempObject1 = Encyclopedia.enemyInfo(32);
                    this.tempObject.nameTXT.text = this.tempObject1[0];
                    this.tempObject.healthTXT.text = this.tempObject1[1];
                    this.tempObject.speedTXT.text = this.tempObject1[2];
                    this.tempObject.penaltyTXT.text = this.tempObject1[3];
                    this.tempObject.fireResistTXT.text = this.tempObject1[4];
                    this.tempObject.iceResistTXT.text = this.tempObject1[5];
                    this.tempObject.stoneResistTXT.text = this.tempObject1[6];
                    this.tempObject.levinResistTXT.text = this.tempObject1[7];
                }
                else
                {
                    this.tempObject.gotoAndStop(2);
                }
                this.tempObject.btnRight.visible = false;
            }
            else if (param2 == 11 || param2 == -11)
            {
                if (param2 == 11)
                {
                    this.tempObject = this.container.book.towerPageRight1;
                }
                else
                {
                    this.tempObject = this.container.book.towerPageRight2;
                }
                if (param1 == "tower1")
                {
                    this.tempObject.gotoAndStop(1);
                }
                else if (param1 == "tower2")
                {
                    this.tempObject.gotoAndStop(2);
                }
                else if (param1 == "tower3")
                {
                    this.tempObject.gotoAndStop(3);
                }
                else if (param1 == "tower4")
                {
                    this.tempObject.gotoAndStop(4);
                }
                else if (param1 == "tower5")
                {
                    this.tempObject.gotoAndStop(5);
                }
                else if (param1 == "tower6")
                {
                    this.tempObject.gotoAndStop(6);
                }
                else
                {
                    this.tempObject.gotoAndStop(15);
                }
            }
            else if (param2 == 12 || param2 == -12)
            {
                if (param2 == 12)
                {
                    this.tempObject = this.container.book.towerPageRight1;
                }
                else
                {
                    this.tempObject = this.container.book.towerPageRight2;
                }
                if (param1 == "tower1")
                {
                    this.tempObject.gotoAndStop(7);
                }
                else if (param1 == "tower2")
                {
                    this.tempObject.gotoAndStop(8);
                }
                else if (param1 == "tower3")
                {
                    this.tempObject.gotoAndStop(9);
                }
                else if (param1 == "tower4")
                {
                    this.tempObject.gotoAndStop(10);
                }
                else
                {
                    this.tempObject.gotoAndStop(15);
                }
            }
            else if (param2 == 13 || param2 == -13)
            {
                if (param2 == 13)
                {
                    this.tempObject = this.container.book.towerPageRight1;
                }
                else
                {
                    this.tempObject = this.container.book.towerPageRight2;
                }
                if (param1 == "tower1")
                {
                    this.tempObject.gotoAndStop(11);
                }
                else if (param1 == "tower2")
                {
                    this.tempObject.gotoAndStop(12);
                }
                else if (param1 == "tower3")
                {
                    this.tempObject.gotoAndStop(13);
                }
                else if (param1 == "tower4")
                {
                    this.tempObject.gotoAndStop(14);
                }
                else
                {
                    this.tempObject.gotoAndStop(15);
                }
                this.tempObject.btnRight.visible = false;
            }
            this.pageStop();
            return;
        }// end function

        public function boardManage(param1:int) : void
        {
            if (param1 == 1 || param1 == -1)
            {
                if (param1 == 1)
                {
                    this.tempObject = this.container.book.enemyPageLeft1;
                }
                else
                {
                    this.tempObject = this.container.book.enemyPageLeft2;
                }
                this.tempObject.enemy1.cont.gotoAndStop(3);
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[1] == 1)
                {
                    this.tempObject.enemy2.cont.gotoAndStop(4);
                }
                else
                {
                    this.tempObject.enemy2.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[2] == 1)
                {
                    this.tempObject.enemy3.cont.gotoAndStop(5);
                }
                else
                {
                    this.tempObject.enemy3.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[3] == 1)
                {
                    this.tempObject.enemy4.cont.gotoAndStop(6);
                }
                else
                {
                    this.tempObject.enemy4.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[4] == 1)
                {
                    this.tempObject.enemy5.cont.gotoAndStop(7);
                }
                else
                {
                    this.tempObject.enemy5.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[5] == 1)
                {
                    this.tempObject.enemy6.cont.gotoAndStop(8);
                }
                else
                {
                    this.tempObject.enemy6.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[6] == 1)
                {
                    this.tempObject.enemy7.cont.gotoAndStop(9);
                }
                else
                {
                    this.tempObject.enemy7.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[7] == 1)
                {
                    this.tempObject.enemy8.cont.gotoAndStop(10);
                }
                else
                {
                    this.tempObject.enemy8.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[8] == 1)
                {
                    this.tempObject.enemy9.cont.gotoAndStop(11);
                }
                else
                {
                    this.tempObject.enemy9.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[9] == 1)
                {
                    this.tempObject.enemy10.cont.gotoAndStop(12);
                }
                else
                {
                    this.tempObject.enemy10.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[10] == 1)
                {
                    this.tempObject.enemy11.cont.gotoAndStop(13);
                }
                else
                {
                    this.tempObject.enemy11.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[11] == 1)
                {
                    this.tempObject.enemy12.cont.gotoAndStop(14);
                }
                else
                {
                    this.tempObject.enemy12.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[12] == 1)
                {
                    this.tempObject.enemy13.cont.gotoAndStop(15);
                }
                else
                {
                    this.tempObject.enemy13.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[13] == 1)
                {
                    this.tempObject.enemy14.cont.gotoAndStop(16);
                }
                else
                {
                    this.tempObject.enemy14.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[14] == 1)
                {
                    this.tempObject.enemy15.cont.gotoAndStop(17);
                }
                else
                {
                    this.tempObject.enemy15.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[15] == 1)
                {
                    this.tempObject.enemy16.cont.gotoAndStop(18);
                }
                else
                {
                    this.tempObject.enemy16.gotoAndStop(3);
                }
                this.tempObject.btnLeft.visible = false;
            }
            else if (param1 == 2 || param1 == -2)
            {
                if (param1 == 2)
                {
                    this.tempObject = this.container.book.enemyPageLeft1;
                }
                else
                {
                    this.tempObject = this.container.book.enemyPageLeft2;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[16] == 1)
                {
                    this.tempObject.enemy1.cont.gotoAndStop(19);
                }
                else
                {
                    this.tempObject.enemy1.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[17] == 1)
                {
                    this.tempObject.enemy2.cont.gotoAndStop(20);
                }
                else
                {
                    this.tempObject.enemy2.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[18] == 1)
                {
                    this.tempObject.enemy3.cont.gotoAndStop(21);
                }
                else
                {
                    this.tempObject.enemy3.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[19] == 1)
                {
                    this.tempObject.enemy4.cont.gotoAndStop(22);
                }
                else
                {
                    this.tempObject.enemy4.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[20] == 1)
                {
                    this.tempObject.enemy5.cont.gotoAndStop(23);
                }
                else
                {
                    this.tempObject.enemy5.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[21] == 1)
                {
                    this.tempObject.enemy6.cont.gotoAndStop(24);
                }
                else
                {
                    this.tempObject.enemy6.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[22] == 1)
                {
                    this.tempObject.enemy7.cont.gotoAndStop(25);
                }
                else
                {
                    this.tempObject.enemy7.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[23] == 1)
                {
                    this.tempObject.enemy8.cont.gotoAndStop(26);
                }
                else
                {
                    this.tempObject.enemy8.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[24] == 1)
                {
                    this.tempObject.enemy9.cont.gotoAndStop(27);
                }
                else
                {
                    this.tempObject.enemy9.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[25] == 1)
                {
                    this.tempObject.enemy10.cont.gotoAndStop(28);
                }
                else
                {
                    this.tempObject.enemy10.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[26] == 1)
                {
                    this.tempObject.enemy11.cont.gotoAndStop(29);
                }
                else
                {
                    this.tempObject.enemy11.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[27] == 1)
                {
                    this.tempObject.enemy12.cont.gotoAndStop(30);
                }
                else
                {
                    this.tempObject.enemy12.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[28] == 1)
                {
                    this.tempObject.enemy13.cont.gotoAndStop(31);
                    this.tempObject.enemy13.cont.enemyCont.cont.gotoAndStop(34);
                }
                else
                {
                    this.tempObject.enemy13.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[29] == 1)
                {
                    this.tempObject.enemy14.cont.gotoAndStop(32);
                    this.tempObject.enemy14.cont.enemyCont.cont.gotoAndStop(34);
                }
                else
                {
                    this.tempObject.enemy14.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[30] == 1)
                {
                    this.tempObject.enemy15.cont.gotoAndStop(33);
                }
                else
                {
                    this.tempObject.enemy15.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewEnemies[31] == 1)
                {
                    this.tempObject.enemy16.cont.gotoAndStop(34);
                }
                else
                {
                    this.tempObject.enemy16.gotoAndStop(3);
                }
            }
            else if (param1 == 11 || param1 == -11)
            {
                if (param1 == 11)
                {
                    this.tempObject = this.container.book.towerPageLeft1;
                }
                else
                {
                    this.tempObject = this.container.book.towerPageLeft2;
                }
                this.tempObject.gotoAndStop(1);
                this.tempObject.tower1.cont.gotoAndStop(1);
                this.tempObject.tower2.cont.gotoAndStop(2);
                if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[1] > 0)
                {
                    this.tempObject.tower3.cont.gotoAndStop(3);
                }
                else
                {
                    this.tempObject.tower3.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[2] > 0)
                {
                    this.tempObject.tower4.cont.gotoAndStop(4);
                }
                else
                {
                    this.tempObject.tower4.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[1] > 0)
                {
                    this.tempObject.tower5.cont.gotoAndStop(5);
                }
                else
                {
                    this.tempObject.tower5.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[2] > 0)
                {
                    this.tempObject.tower6.cont.gotoAndStop(6);
                }
                else
                {
                    this.tempObject.tower6.gotoAndStop(3);
                }
                this.tempObject.btnLeft.visible = false;
            }
            else if (param1 == 12 || param1 == -12)
            {
                if (param1 == 12)
                {
                    this.tempObject = this.container.book.towerPageLeft1;
                }
                else
                {
                    this.tempObject = this.container.book.towerPageLeft2;
                }
                this.tempObject.gotoAndStop(2);
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[0] == 1)
                {
                    this.tempObject.tower1.cont.gotoAndStop(7);
                }
                else
                {
                    this.tempObject.tower1.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[1] == 1)
                {
                    this.tempObject.tower2.cont.gotoAndStop(8);
                }
                else
                {
                    this.tempObject.tower2.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[2] == 1)
                {
                    this.tempObject.tower3.cont.gotoAndStop(9);
                }
                else
                {
                    this.tempObject.tower3.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[3] == 1)
                {
                    this.tempObject.tower4.cont.gotoAndStop(10);
                }
                else
                {
                    this.tempObject.tower4.gotoAndStop(3);
                }
            }
            else if (param1 == 13 || param1 == -13)
            {
                if (param1 == 13)
                {
                    this.tempObject = this.container.book.towerPageLeft1;
                }
                else
                {
                    this.tempObject = this.container.book.towerPageLeft2;
                }
                this.tempObject.gotoAndStop(2);
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[4] == 1)
                {
                    this.tempObject.tower1.cont.gotoAndStop(11);
                }
                else
                {
                    this.tempObject.tower1.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[5] == 1)
                {
                    this.tempObject.tower2.cont.gotoAndStop(12);
                }
                else
                {
                    this.tempObject.tower2.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[6] == 1)
                {
                    this.tempObject.tower3.cont.gotoAndStop(13);
                }
                else
                {
                    this.tempObject.tower3.gotoAndStop(3);
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[7] == 1)
                {
                    this.tempObject.tower4.cont.gotoAndStop(14);
                    this.tempObject.tower4.cont.towerCont.stop();
                    this.tempObject.tower4.cont.towerCont.cont2.stop();
                }
                else
                {
                    this.tempObject.tower4.gotoAndStop(3);
                }
            }
            this.pageStop();
            return;
        }// end function

        public function enemiesMouseMoveDefault() : void
        {
            if (this.container.book.enemyPageLeft1.enemy1.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy1 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy1.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy2.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy2 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy2.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy3.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy3 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy3.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy4.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy4 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy4.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy5.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy5 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy5.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy6.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy6 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy6.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy7.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy7 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy7.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy8.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy8 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy8.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy9.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy9 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy9.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy10.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy10 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy10.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy11.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy11 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy11.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy12.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy12 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy12.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy13.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy13 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy13.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy14.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy14 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy14.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy15.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy15 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy15.gotoAndStop(1);
                }
            }
            if (this.container.book.enemyPageLeft1.enemy16.currentFrame == 2)
            {
                if (this.container.book.enemyPageLeft1.enemy16 != this.nowTarget)
                {
                    this.container.book.enemyPageLeft1.enemy16.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function towersMouseMoveDefault() : void
        {
            if (this.container.book.towerPageLeft1.tower1.currentFrame == 2)
            {
                if (this.container.book.towerPageLeft1.tower1 != this.nowTarget)
                {
                    this.container.book.towerPageLeft1.tower1.gotoAndStop(1);
                }
            }
            if (this.container.book.towerPageLeft1.tower2.currentFrame == 2)
            {
                if (this.container.book.towerPageLeft1.tower2 != this.nowTarget)
                {
                    this.container.book.towerPageLeft1.tower2.gotoAndStop(1);
                }
            }
            if (this.container.book.towerPageLeft1.tower3.currentFrame == 2)
            {
                if (this.container.book.towerPageLeft1.tower3 != this.nowTarget)
                {
                    this.container.book.towerPageLeft1.tower3.gotoAndStop(1);
                }
            }
            if (this.container.book.towerPageLeft1.tower4.currentFrame == 2)
            {
                if (this.container.book.towerPageLeft1.tower4 != this.nowTarget)
                {
                    this.container.book.towerPageLeft1.tower4.gotoAndStop(1);
                }
            }
            if (this.container.book.towerPageLeft1.tower5)
            {
                if (this.container.book.towerPageLeft1.tower5.currentFrame == 2)
                {
                    if (this.container.book.towerPageLeft1.tower5 != this.nowTarget)
                    {
                        this.container.book.towerPageLeft1.tower5.gotoAndStop(1);
                    }
                }
                if (this.container.book.towerPageLeft1.tower6.currentFrame == 2)
                {
                    if (this.container.book.towerPageLeft1.tower6 != this.nowTarget)
                    {
                        this.container.book.towerPageLeft1.tower6.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(this.mouseX, this.mouseY);
            this.autoguidesObject = null;
            if (this.nowPage < 11)
            {
                if (this.container.book.enemyPageLeft1.btnLeft.visible)
                {
                    this.autoguidesObject_pt = this.container.book.enemyPageLeft1.btnLeft.localToGlobal(new Point(this.container.book.enemyPageLeft1.btnLeft.arrowCase.x, this.container.book.enemyPageLeft1.btnLeft.arrowCase.y));
                    this.autoguidesObjectWidth = this.container.book.enemyPageLeft1.btnLeft.arrowCase.width / 2;
                    this.autoguidesObjectHeight = this.container.book.enemyPageLeft1.btnLeft.arrowCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.book.enemyPageLeft1.btnLeft.arrowCase;
                    }
                }
                if (this.container.book.enemyPageRight1.btnRight.visible)
                {
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.book.enemyPageRight1.btnRight.localToGlobal(new Point(this.container.book.enemyPageRight1.btnRight.arrowCase.x, this.container.book.enemyPageRight1.btnRight.arrowCase.y));
                        this.autoguidesObjectWidth = this.container.book.enemyPageRight1.btnRight.arrowCase.width / 2;
                        this.autoguidesObjectHeight = this.container.book.enemyPageRight1.btnRight.arrowCase.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.book.enemyPageRight1.btnRight.arrowCase;
                        }
                    }
                }
            }
            else
            {
                if (this.container.book.towerPageLeft1.btnLeft.visible)
                {
                    this.autoguidesObject_pt = this.container.book.towerPageLeft1.btnLeft.localToGlobal(new Point(this.container.book.towerPageLeft1.btnLeft.arrowCase.x, this.container.book.towerPageLeft1.btnLeft.arrowCase.y));
                    this.autoguidesObjectWidth = this.container.book.towerPageLeft1.btnLeft.arrowCase.width / 2;
                    this.autoguidesObjectHeight = this.container.book.towerPageLeft1.btnLeft.arrowCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.book.towerPageLeft1.btnLeft.arrowCase;
                    }
                }
                if (this.container.book.towerPageRight1.btnRight.visible)
                {
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.book.towerPageRight1.btnRight.localToGlobal(new Point(this.container.book.towerPageRight1.btnRight.arrowCase.x, this.container.book.towerPageRight1.btnRight.arrowCase.y));
                        this.autoguidesObjectWidth = this.container.book.towerPageRight1.btnRight.arrowCase.width / 2;
                        this.autoguidesObjectHeight = this.container.book.towerPageRight1.btnRight.arrowCase.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.book.towerPageRight1.btnRight.arrowCase;
                        }
                    }
                }
            }
            if (this.autoguidesObject)
            {
                this.tempObject = new Object();
                this.tempObject.target = this.autoguidesObject;
                this.mouseMoveHandler(this.tempObject);
            }
            return;
        }// end function

        public function close() : void
        {
            if (!this.closeFlag)
            {
                this.closeFlag = true;
                var _loc_1:* = false;
                this.container.book.setMouseChildren(false);
                this.container.book.mouseEnabled = _loc_1;
                if (Main.mainClass.levelsMenuClass)
                {
                    Main.mainClass.levelsMenuClass.container.book.gotoAndStop(1);
                }
                this.stage.frameRate = 60;
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                if (!Main.mainClass.worldClass)
                {
                    Main.mainClass.levelsMenuClass.manageListeners("on");
                    Main.mainClass.levelsMenuClass.removeChild(this);
                    Main.mainClass.levelsMenuClass.encyclopediaClass = null;
                }
                else
                {
                    Main.mainClass.worldClass.manageListeners("on");
                    if (Main.mainClass.worldClass.getSphere || Main.mainClass.worldClass.cast)
                    {
                        Main.mainClass.worldClass.manageMouse("hide");
                    }
                    Main.mainClass.worldClass.removeChild(this);
                    Main.mainClass.worldClass.menuObject = null;
                }
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            this.stage.frameRate = 30;
            return;
        }// end function

        public static function enemyInfo(param1:int) : Array
        {
            var _loc_2:* = [];
            if (param1 == 1)
            {
                _loc_2.push("木头脑袋");
                _loc_2.push("50");
                _loc_2.push("一般");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 2)
            {
                _loc_2.push("骑士");
                _loc_2.push("250");
                _loc_2.push("慢");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 3)
            {
                _loc_2.push("有翼跳跃者");
                _loc_2.push("135");
                _loc_2.push("非常快");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 4)
            {
                _loc_2.push("日光骑士");
                _loc_2.push("470");
                _loc_2.push("慢");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 5)
            {
                _loc_2.push("勇猛骑士");
                _loc_2.push("1800");
                _loc_2.push("非常慢");
                _loc_2.push("2");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 6)
            {
                _loc_2.push("火焰大头");
                _loc_2.push("500");
                _loc_2.push("慢");
                _loc_2.push("2");
                _loc_2.push("中");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 7)
            {
                _loc_2.push("寒冰大头");
                _loc_2.push("620");
                _loc_2.push("非常慢");
                _loc_2.push("2");
                _loc_2.push("无");
                _loc_2.push("中");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 8)
            {
                _loc_2.push("迅捷跳跃者");
                _loc_2.push("330");
                _loc_2.push("非常快");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 9)
            {
                _loc_2.push("霜冻巨石");
                _loc_2.push("1500");
                _loc_2.push("慢");
                _loc_2.push("2");
                _loc_2.push("无");
                _loc_2.push("中");
                _loc_2.push("中");
                _loc_2.push("无");
            }
            else if (param1 == 10)
            {
                _loc_2.push("维京");
                _loc_2.push("1200");
                _loc_2.push("快");
                _loc_2.push("2");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 11)
            {
                _loc_2.push("火焰巨石");
                _loc_2.push("1600");
                _loc_2.push("慢");
                _loc_2.push("2");
                _loc_2.push("中");
                _loc_2.push("无");
                _loc_2.push("中");
                _loc_2.push("无");
            }
            else if (param1 == 12)
            {
                _loc_2.push("巨石大头");
                _loc_2.push("750");
                _loc_2.push("非常慢");
                _loc_2.push("2");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("中");
                _loc_2.push("无");
            }
            else if (param1 == 13)
            {
                _loc_2.push("有翼指挥官");
                _loc_2.push("550");
                _loc_2.push("非常快");
                _loc_2.push("1");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 14)
            {
                _loc_2.push("勇猛维京");
                _loc_2.push("2000");
                _loc_2.push("一般");
                _loc_2.push("2");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 15)
            {
                _loc_2.push("维京首领");
                _loc_2.push("2600");
                _loc_2.push("慢");
                _loc_2.push("2");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 16)
            {
                _loc_2.push("闪电大头");
                _loc_2.push("800");
                _loc_2.push("慢");
                _loc_2.push("2");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("中");
            }
            else if (param1 == 17)
            {
                _loc_2.push("闪电巨石");
                _loc_2.push("1700");
                _loc_2.push("一般");
                _loc_2.push("2");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("中");
                _loc_2.push("中");
            }
            else if (param1 == 18)
            {
                _loc_2.push("刺客");
                _loc_2.push("850");
                _loc_2.push("快");
                _loc_2.push("2");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 19)
            {
                _loc_2.push("暗影刺客");
                _loc_2.push("1800");
                _loc_2.push("一般");
                _loc_2.push("2");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 20)
            {
                _loc_2.push("罗马盾牌");
                _loc_2.push("1700");
                _loc_2.push("非常慢");
                _loc_2.push("3");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 21)
            {
                _loc_2.push("罗马 «乌龟»");
                _loc_2.push("2500");
                _loc_2.push("非常慢");
                _loc_2.push("3");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 22)
            {
                _loc_2.push("法师");
                _loc_2.push("550");
                _loc_2.push("非常慢");
                _loc_2.push("2");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 23)
            {
                _loc_2.push("火焰精灵");
                _loc_2.push("1400");
                _loc_2.push("一般");
                _loc_2.push("3");
                _loc_2.push("高");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 24)
            {
                _loc_2.push("寒冰精灵");
                _loc_2.push("1600");
                _loc_2.push("慢");
                _loc_2.push("3");
                _loc_2.push("无");
                _loc_2.push("高");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 25)
            {
                _loc_2.push("岩石精灵");
                _loc_2.push("2000");
                _loc_2.push("非常慢");
                _loc_2.push("3");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("高");
                _loc_2.push("无");
            }
            else if (param1 == 26)
            {
                _loc_2.push("闪电精灵");
                _loc_2.push("2300");
                _loc_2.push("非常慢");
                _loc_2.push("3");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("高");
            }
            else if (param1 == 27)
            {
                _loc_2.push("传送大师");
                _loc_2.push("1200");
                _loc_2.push("慢");
                _loc_2.push("2");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 28)
            {
                _loc_2.push("高等萨满");
                _loc_2.push("1800");
                _loc_2.push("慢");
                _loc_2.push("2");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
                _loc_2.push("低");
            }
            else if (param1 == 29)
            {
                _loc_2.push("沙质大头");
                _loc_2.push("400");
                _loc_2.push("快");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 30)
            {
                _loc_2.push("沙漠大头");
                _loc_2.push("900");
                _loc_2.push("一般");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 31)
            {
                _loc_2.push("突击手");
                _loc_2.push("350");
                _loc_2.push("快");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 32)
            {
                _loc_2.push("兰博");
                _loc_2.push("500");
                _loc_2.push("快");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 33)
            {
                _loc_2.push("暴风");
                _loc_2.push("450");
                _loc_2.push("快");
                _loc_2.push("1");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
                _loc_2.push("无");
            }
            else if (param1 == 34)
            {
                _loc_2.push("Boss");
                _loc_2.push("23000");
                _loc_2.push("无");
                _loc_2.push("20");
                _loc_2.push("中");
                _loc_2.push("中");
                _loc_2.push("中");
                _loc_2.push("中");
            }
            return _loc_2;
        }// end function

    }
}
