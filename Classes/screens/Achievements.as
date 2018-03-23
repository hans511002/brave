package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Achievements extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:Achievements_mc;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var page:int;
        public var fireFrame:int = 0;
        public var dead:Boolean;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function Achievements()
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
            Main.mainClass.levelsMenuClass.manageListeners("off");
            this.container = new Achievements_mc();
            this.container.stop();
            this.container.back.stop();
            this.container.back.backCase.stop();
            this.container.back.backCase.buttonMode = true;
            this.container.cont.stop();
            this.container.cont.achieve1.stop();
            this.container.cont.achieve2.stop();
            this.container.cont.achieve3.stop();
            this.container.cont.achieve4.stop();
            this.container.cont.achieve5.stop();
            this.container.cont.achieve6.stop();
            this.container.cont.achieve7.stop();
            this.container.cont.achieve8.stop();
            this.container.cont.achieve9.stop();
            this.container.cont.achieve10.stop();
            this.container.cont.btnBack.stop();
            this.container.cont.btnBack.arrowCase.stop();
            this.container.cont.btnForward.stop();
            this.container.cont.btnForward.arrowCase.stop();
            this.container.cont.btnClose.stop();
            this.container.cont.btnClose.closeCase.stop();
            this.container.cont.fire1.stop();
            this.container.cont.fire2.stop();
            this.container.cont.fire3.stop();
            this.container.cont.fire4.stop();
            this.container.cont.fire5.stop();
            this.container.cont.fire1Case.stop();
            this.container.cont.fire2Case.stop();
            this.container.cont.fire3Case.stop();
            this.container.cont.fire4Case.stop();
            this.container.cont.fire5Case.stop();
            this.container.cont.btnBack.arrowCase.buttonMode = true;
            this.container.cont.btnForward.arrowCase.buttonMode = true;
            this.container.cont.btnClose.closeCase.buttonMode = true;
            this.pageManage(1);
            var _loc_2:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_2;
            this.addChild(this.container);
            Sounds.instance.playSound("snd_menu_openBoard");
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
                    this.container.cont.mouseChildren = true;
                    this.container.cont.mouseEnabled = _loc_2;
                    this.autoguidersButtons();
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
            if (this.container.cont.fire1.visible)
            {
                if (this.fireFrame < this.container.cont.fire1.totalFrames)
                {
                    (this.fireFrame + 1);
                }
                else
                {
                    this.fireFrame = 1;
                }
                this.container.cont.fire1.gotoAndStop(this.fireFrame);
            }
            else if (this.container.cont.fire2.visible)
            {
                if (this.fireFrame < this.container.cont.fire2.totalFrames)
                {
                    (this.fireFrame + 1);
                }
                else
                {
                    this.fireFrame = 1;
                }
                this.container.cont.fire2.gotoAndStop(this.fireFrame);
            }
            else if (this.container.cont.fire3.visible)
            {
                if (this.fireFrame < this.container.cont.fire3.totalFrames)
                {
                    (this.fireFrame + 1);
                }
                else
                {
                    this.fireFrame = 1;
                }
                this.container.cont.fire3.gotoAndStop(this.fireFrame);
            }
            else if (this.container.cont.fire4.visible)
            {
                if (this.fireFrame < this.container.cont.fire4.totalFrames)
                {
                    (this.fireFrame + 1);
                }
                else
                {
                    this.fireFrame = 1;
                }
                this.container.cont.fire4.gotoAndStop(this.fireFrame);
            }
            else if (this.container.cont.fire5.visible)
            {
                if (this.fireFrame < this.container.cont.fire5.totalFrames)
                {
                    (this.fireFrame + 1);
                }
                else
                {
                    this.fireFrame = 1;
                }
                this.container.cont.fire5.gotoAndStop(this.fireFrame);
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "backCase")
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
            if (param1.target.name == "closeCase")
            {
                if (this.container.cont.btnClose.currentFrame == 1)
                {
                    this.container.cont.btnClose.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.btnClose.currentFrame == 2)
            {
                this.container.cont.btnClose.gotoAndStop(1);
            }
            if (param1.target.parent.name == "btnBack")
            {
                if (this.container.cont.btnBack.currentFrame == 1)
                {
                    this.container.cont.btnBack.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.btnBack.currentFrame == 2)
            {
                this.container.cont.btnBack.gotoAndStop(1);
            }
            if (param1.target.parent.name == "btnForward")
            {
                if (this.container.cont.btnForward.currentFrame == 1)
                {
                    this.container.cont.btnForward.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.btnForward.currentFrame == 2)
            {
                this.container.cont.btnForward.gotoAndStop(1);
            }
            if (param1.target.name == "fire1Case")
            {
                if (!param1.target.mouseMoveFlag)
                {
                    param1.target.mouseMoveFlag = true;
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.fire1Case.mouseMoveFlag)
            {
                this.container.cont.fire1Case.mouseMoveFlag = false;
            }
            if (param1.target.name == "fire2Case")
            {
                if (!param1.target.mouseMoveFlag)
                {
                    param1.target.mouseMoveFlag = true;
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.fire2Case.mouseMoveFlag)
            {
                this.container.cont.fire2Case.mouseMoveFlag = false;
            }
            if (param1.target.name == "fire3Case")
            {
                if (!param1.target.mouseMoveFlag)
                {
                    param1.target.mouseMoveFlag = true;
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.fire3Case.mouseMoveFlag)
            {
                this.container.cont.fire3Case.mouseMoveFlag = false;
            }
            if (param1.target.name == "fire4Case")
            {
                if (!param1.target.mouseMoveFlag)
                {
                    param1.target.mouseMoveFlag = true;
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.fire4Case.mouseMoveFlag)
            {
                this.container.cont.fire4Case.mouseMoveFlag = false;
            }
            if (param1.target.name == "fire5Case")
            {
                if (!param1.target.mouseMoveFlag)
                {
                    param1.target.mouseMoveFlag = true;
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.fire5Case.mouseMoveFlag)
            {
                this.container.cont.fire5Case.mouseMoveFlag = false;
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (!this.openFlag)
            {
                if (event.target.name == "backCase")
                {
                    if (this.container.back.currentFrame == 2)
                    {
                        this.container.back.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "closeCase")
                {
                    if (this.container.cont.btnClose.currentFrame == 2)
                    {
                        this.container.cont.btnClose.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.parent.name == "btnBack")
                {
                    if (this.container.cont.btnBack.currentFrame == 2)
                    {
                        this.container.cont.btnBack.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.parent.name == "btnForward")
                {
                    if (this.container.cont.btnForward.currentFrame == 2)
                    {
                        this.container.cont.btnForward.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "fire1Case")
                {
                    if (this.container.cont.fire1Case.buttonMode)
                    {
                        this.pageManage(1);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "fire2Case")
                {
                    if (this.container.cont.fire2Case.buttonMode)
                    {
                        this.pageManage(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "fire3Case")
                {
                    if (this.container.cont.fire3Case.buttonMode)
                    {
                        this.pageManage(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "fire4Case")
                {
                    if (this.container.cont.fire4Case.buttonMode)
                    {
                        this.pageManage(4);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "fire5Case")
                {
                    if (this.container.cont.fire5Case.buttonMode)
                    {
                        this.pageManage(5);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
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
            if (event.target.name == "closeCase")
            {
                if (this.container.cont.btnClose.currentFrame == 3)
                {
                    this.container.cont.btnClose.gotoAndStop(2);
                    this.close();
                }
            }
            else if (this.container.cont.btnClose.currentFrame == 3)
            {
                this.container.cont.btnClose.gotoAndStop(1);
            }
            if (event.target.parent.name == "btnBack")
            {
                if (this.container.cont.btnBack.currentFrame == 3)
                {
                    this.container.cont.btnBack.gotoAndStop(2);
                    this.pageManage((this.page - 1));
                }
            }
            else if (this.container.cont.btnBack.currentFrame == 3)
            {
                this.container.cont.btnBack.gotoAndStop(1);
            }
            if (event.target.parent.name == "btnForward")
            {
                if (this.container.cont.btnForward.currentFrame == 3)
                {
                    this.container.cont.btnForward.gotoAndStop(2);
                    this.pageManage((this.page + 1));
                }
            }
            else if (this.container.cont.btnForward.currentFrame == 3)
            {
                this.container.cont.btnForward.gotoAndStop(1);
            }
            return;
        }// end function

        public function pageManage(param1:int) : void
        {
            if (param1 < 1)
            {
                param1 = 5;
            }
            else if (param1 > 5)
            {
                param1 = 1;
            }
            this.page = param1;
            if (!this.container.cont.achieve1.visible)
            {
                this.container.cont.achieve1.visible = true;
            }
            if (!this.container.cont.achieve2.visible)
            {
                this.container.cont.achieve2.visible = true;
            }
            if (!this.container.cont.achieve3.visible)
            {
                this.container.cont.achieve3.visible = true;
            }
            if (!this.container.cont.achieve4.visible)
            {
                this.container.cont.achieve4.visible = true;
            }
            if (!this.container.cont.achieve5.visible)
            {
                this.container.cont.achieve5.visible = true;
            }
            if (!this.container.cont.achieve6.visible)
            {
                this.container.cont.achieve6.visible = true;
            }
            if (!this.container.cont.achieve7.visible)
            {
                this.container.cont.achieve7.visible = true;
            }
            if (!this.container.cont.achieve8.visible)
            {
                this.container.cont.achieve8.visible = true;
            }
            if (!this.container.cont.achieve9.visible)
            {
                this.container.cont.achieve9.visible = true;
            }
            if (!this.container.cont.achieve10.visible)
            {
                this.container.cont.achieve10.visible = true;
            }
            if (this.container.cont.fire1.visible)
            {
                this.container.cont.fire1.visible = false;
            }
            if (this.container.cont.fire2.visible)
            {
                this.container.cont.fire2.visible = false;
            }
            if (this.container.cont.fire3.visible)
            {
                this.container.cont.fire3.visible = false;
            }
            if (this.container.cont.fire4.visible)
            {
                this.container.cont.fire4.visible = false;
            }
            if (this.container.cont.fire5.visible)
            {
                this.container.cont.fire5.visible = false;
            }
            if (!this.container.cont.fire1Case.buttonMode)
            {
                this.container.cont.fire1Case.buttonMode = true;
            }
            if (!this.container.cont.fire2Case.buttonMode)
            {
                this.container.cont.fire2Case.buttonMode = true;
            }
            if (!this.container.cont.fire3Case.buttonMode)
            {
                this.container.cont.fire3Case.buttonMode = true;
            }
            if (!this.container.cont.fire4Case.buttonMode)
            {
                this.container.cont.fire4Case.buttonMode = true;
            }
            if (!this.container.cont.fire5Case.buttonMode)
            {
                this.container.cont.fire5Case.buttonMode = true;
            }
            if (param1 == 1)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_firstKill)
                {
                    this.container.cont.achieve1.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve1.gotoAndStop(2);
                }
                this.container.cont.achieve1.icon.gotoAndStop(1);
                this.container.cont.achieve1.nameTXT.text = "第一滴血";
                this.container.cont.achieve1.noteTXT.text = "杀死 1 名敌人【U77总有好游戏】";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_kill_100_enemies)
                {
                    this.container.cont.achieve2.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve2.gotoAndStop(2);
                }
                this.container.cont.achieve2.icon.gotoAndStop(2);
                this.container.cont.achieve2.nameTXT.text = "热烈无比";
                this.container.cont.achieve2.noteTXT.text = "在一场游戏中杀死 100 名敌人";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_kill_2500_enemies)
                {
                    this.container.cont.achieve3.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve3.gotoAndStop(2);
                }
                this.container.cont.achieve3.icon.gotoAndStop(3);
                this.container.cont.achieve3.nameTXT.text = "杀手";
                this.container.cont.achieve3.noteTXT.text = "杀死 2500 名敌人";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_call_100_earlyWaves)
                {
                    this.container.cont.achieve4.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve4.gotoAndStop(2);
                }
                this.container.cont.achieve4.icon.gotoAndStop(4);
                this.container.cont.achieve4.nameTXT.text = "毫无畏惧";
                this.container.cont.achieve4.noteTXT.text = "提前召唤 100 波次";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_build_100_towers)
                {
                    this.container.cont.achieve5.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve5.gotoAndStop(2);
                }
                this.container.cont.achieve5.icon.gotoAndStop(5);
                this.container.cont.achieve5.nameTXT.text = "建造者";
                this.container.cont.achieve5.noteTXT.text = "建造 100 座塔楼";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_createGolem_5_times)
                {
                    this.container.cont.achieve6.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve6.gotoAndStop(2);
                }
                this.container.cont.achieve6.icon.gotoAndStop(6);
                this.container.cont.achieve6.nameTXT.text = "巨型支援";
                this.container.cont.achieve6.noteTXT.text = "一场任务中召唤 5 次击碎者";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_createIceman_15_times)
                {
                    this.container.cont.achieve7.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve7.gotoAndStop(2);
                }
                this.container.cont.achieve7.icon.gotoAndStop(7);
                this.container.cont.achieve7.nameTXT.text = "缓和";
                this.container.cont.achieve7.noteTXT.text = "一场任务中召唤 15 次冰冻者";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_createAir_7_times)
                {
                    this.container.cont.achieve8.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve8.gotoAndStop(2);
                }
                this.container.cont.achieve8.icon.gotoAndStop(8);
                this.container.cont.achieve8.nameTXT.text = "远古支援";
                this.container.cont.achieve8.noteTXT.text = "一场任务中召唤 7 次复活岛巨像";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_callAllWavesInLevel)
                {
                    this.container.cont.achieve9.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve9.gotoAndStop(2);
                }
                this.container.cont.achieve9.icon.gotoAndStop(9);
                this.container.cont.achieve9.nameTXT.text = "大胆";
                this.container.cont.achieve9.noteTXT.text = "一场任务中提前召唤所有波次";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_sellFireIceStoneLevin)
                {
                    this.container.cont.achieve10.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve10.gotoAndStop(2);
                }
                this.container.cont.achieve10.icon.gotoAndStop(10);
                this.container.cont.achieve10.nameTXT.text = "破坏者";
                this.container.cont.achieve10.noteTXT.text = "一场任务中出售所有类型元素";
                this.container.cont.fire1.visible = true;
                this.container.cont.fire1Case.buttonMode = false;
            }
            else if (param1 == 2)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_sellFire_10_times)
                {
                    this.container.cont.achieve1.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve1.gotoAndStop(2);
                }
                this.container.cont.achieve1.icon.gotoAndStop(11);
                this.container.cont.achieve1.nameTXT.text = "火焰破坏者";
                this.container.cont.achieve1.noteTXT.text = "出售 10 次火焰元素【U 7 7 汉化】";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_sellIce_10_times)
                {
                    this.container.cont.achieve2.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve2.gotoAndStop(2);
                }
                this.container.cont.achieve2.icon.gotoAndStop(12);
                this.container.cont.achieve2.nameTXT.text = "寒冰破坏者";
                this.container.cont.achieve2.noteTXT.text = "出售 10 次寒冰元素";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_sellStone_10_times)
                {
                    this.container.cont.achieve3.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve3.gotoAndStop(2);
                }
                this.container.cont.achieve3.icon.gotoAndStop(13);
                this.container.cont.achieve3.nameTXT.text = "巨石破坏者";
                this.container.cont.achieve3.noteTXT.text = "出售 10 次岩石元素";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_sellLevin_10_times)
                {
                    this.container.cont.achieve4.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve4.gotoAndStop(2);
                }
                this.container.cont.achieve4.icon.gotoAndStop(14);
                this.container.cont.achieve4.nameTXT.text = "闪电破坏者";
                this.container.cont.achieve4.noteTXT.text = "出售 10 次闪电元素";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_golemKill_250_enemies)
                {
                    this.container.cont.achieve5.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve5.gotoAndStop(2);
                }
                this.container.cont.achieve5.icon.gotoAndStop(15);
                this.container.cont.achieve5.nameTXT.text = "粉碎者";
                this.container.cont.achieve5.noteTXT.text = "击碎者碾碎 250 个大头";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_icemanSlowdown_75_enemies)
                {
                    this.container.cont.achieve6.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve6.gotoAndStop(2);
                }
                this.container.cont.achieve6.icon.gotoAndStop(16);
                this.container.cont.achieve6.nameTXT.text = "有点冷";
                this.container.cont.achieve6.noteTXT.text = "一场任务中冰冻 75 个单位";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_icemanSlowdown_500_enemies)
                {
                    this.container.cont.achieve7.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve7.gotoAndStop(2);
                }
                this.container.cont.achieve7.icon.gotoAndStop(17);
                this.container.cont.achieve7.nameTXT.text = "霜冻力量";
                this.container.cont.achieve7.noteTXT.text = "冰冻者冰冻 500 个大头";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_buildUltraTower)
                {
                    this.container.cont.achieve8.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve8.gotoAndStop(2);
                }
                this.container.cont.achieve8.icon.gotoAndStop(18);
                this.container.cont.achieve8.nameTXT.text = "进阶建造者";
                this.container.cont.achieve8.noteTXT.text = "建造 1 座超级塔楼";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_buildUltraTower_50_times)
                {
                    this.container.cont.achieve9.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve9.gotoAndStop(2);
                }
                this.container.cont.achieve9.icon.gotoAndStop(19);
                this.container.cont.achieve9.nameTXT.text = "专家建造者";
                this.container.cont.achieve9.noteTXT.text = "建造 50 座超级塔楼";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_buildAllUltraTowers)
                {
                    this.container.cont.achieve10.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve10.gotoAndStop(2);
                }
                this.container.cont.achieve10.icon.gotoAndStop(20);
                this.container.cont.achieve10.nameTXT.text = "策略建造者";
                this.container.cont.achieve10.noteTXT.text = "一场游戏中每种类型建造一座超级塔楼总计 4 座";
                this.container.cont.fire2.visible = true;
                this.container.cont.fire2Case.buttonMode = false;
            }
            else if (param1 == 3)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_notCast)
                {
                    this.container.cont.achieve1.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve1.gotoAndStop(2);
                }
                this.container.cont.achieve1.icon.gotoAndStop(21);
                this.container.cont.achieve1.nameTXT.text = "上手";
                this.container.cont.achieve1.noteTXT.text = "一场游戏中不召唤任何元素法术【U77总有好游戏】";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castFire_150_times)
                {
                    this.container.cont.achieve2.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve2.gotoAndStop(2);
                }
                this.container.cont.achieve2.icon.gotoAndStop(22);
                this.container.cont.achieve2.nameTXT.text = "火焰大师";
                this.container.cont.achieve2.noteTXT.text = "召唤 150 次火焰元素";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castIce_150_times)
                {
                    this.container.cont.achieve3.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve3.gotoAndStop(2);
                }
                this.container.cont.achieve3.icon.gotoAndStop(23);
                this.container.cont.achieve3.nameTXT.text = "寒冰大师";
                this.container.cont.achieve3.noteTXT.text = "召唤 150 次寒冰元素";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castStone_150_times)
                {
                    this.container.cont.achieve4.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve4.gotoAndStop(2);
                }
                this.container.cont.achieve4.icon.gotoAndStop(24);
                this.container.cont.achieve4.nameTXT.text = "岩石大师";
                this.container.cont.achieve4.noteTXT.text = "召唤 150 次岩石元素";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castLevin_150_times)
                {
                    this.container.cont.achieve5.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve5.gotoAndStop(2);
                }
                this.container.cont.achieve5.icon.gotoAndStop(25);
                this.container.cont.achieve5.nameTXT.text = "闪电大师";
                this.container.cont.achieve5.noteTXT.text = "召唤 150 次闪电元素";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castGetAll_10_times)
                {
                    this.container.cont.achieve6.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve6.gotoAndStop(2);
                }
                this.container.cont.achieve6.icon.gotoAndStop(26);
                this.container.cont.achieve6.nameTXT.text = "策略爆破者";
                this.container.cont.achieve6.noteTXT.text = "一场游戏中召唤 10 次超级噼里啪啦";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castGetAll_100_times)
                {
                    this.container.cont.achieve7.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve7.gotoAndStop(2);
                }
                this.container.cont.achieve7.icon.gotoAndStop(27);
                this.container.cont.achieve7.nameTXT.text = "爆破者";
                this.container.cont.achieve7.noteTXT.text = "召唤 100 次超级噼里啪啦";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castKill_1_enemy)
                {
                    this.container.cont.achieve8.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve8.gotoAndStop(2);
                }
                this.container.cont.achieve8.icon.gotoAndStop(28);
                this.container.cont.achieve8.nameTXT.text = "施法者";
                this.container.cont.achieve8.noteTXT.text = "召唤任意元素杀死 1 名敌人";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_castKill_100_enemy)
                {
                    this.container.cont.achieve9.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve9.gotoAndStop(2);
                }
                this.container.cont.achieve9.icon.gotoAndStop(29);
                this.container.cont.achieve9.nameTXT.text = "法术杀手";
                this.container.cont.achieve9.noteTXT.text = "召唤任意元素杀死 150 名敌人";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_complete_10_hardLevels)
                {
                    this.container.cont.achieve10.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve10.gotoAndStop(2);
                }
                this.container.cont.achieve10.icon.gotoAndStop(30);
                this.container.cont.achieve10.nameTXT.text = "勇猛战士";
                this.container.cont.achieve10.noteTXT.text = "困难难度下通过 10 关";
                this.container.cont.fire3.visible = true;
                this.container.cont.fire3Case.buttonMode = false;
            }
            else if (param1 == 4)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_complete_10_survivalLevels)
                {
                    this.container.cont.achieve1.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve1.gotoAndStop(2);
                }
                this.container.cont.achieve1.icon.gotoAndStop(31);
                this.container.cont.achieve1.nameTXT.text = "幸存者";
                this.container.cont.achieve1.noteTXT.text = "生存关卡通过 10 关【U 7 7 汉化】";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_complete_10_withAllLives)
                {
                    this.container.cont.achieve2.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve2.gotoAndStop(2);
                }
                this.container.cont.achieve2.icon.gotoAndStop(32);
                this.container.cont.achieve2.nameTXT.text = "活力四射";
                this.container.cont.achieve2.noteTXT.text = "不损失生命值通过 10 关";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_01)
                {
                    this.container.cont.achieve3.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve3.gotoAndStop(2);
                }
                this.container.cont.achieve3.icon.gotoAndStop(33);
                this.container.cont.achieve3.nameTXT.text = "伐木工";
                this.container.cont.achieve3.noteTXT.text = "伙计去伐木";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_02)
                {
                    this.container.cont.achieve4.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve4.gotoAndStop(2);
                }
                this.container.cont.achieve4.icon.gotoAndStop(34);
                this.container.cont.achieve4.nameTXT.text = "忙忙碌碌";
                this.container.cont.achieve4.noteTXT.text = "伙计走开";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_03)
                {
                    this.container.cont.achieve5.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve5.gotoAndStop(2);
                }
                this.container.cont.achieve5.icon.gotoAndStop(35);
                this.container.cont.achieve5.nameTXT.text = "南瓜节";
                this.container.cont.achieve5.noteTXT.text = "失掉 3 个南瓜";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_04)
                {
                    this.container.cont.achieve6.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve6.gotoAndStop(2);
                }
                this.container.cont.achieve6.icon.gotoAndStop(36);
                this.container.cont.achieve6.nameTXT.text = "修理工";
                this.container.cont.achieve6.noteTXT.text = "打到伙计的手指";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_05)
                {
                    this.container.cont.achieve7.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve7.gotoAndStop(2);
                }
                this.container.cont.achieve7.icon.gotoAndStop(37);
                this.container.cont.achieve7.nameTXT.text = "勇士";
                this.container.cont.achieve7.noteTXT.text = "伙计跑到森林里";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_06)
                {
                    this.container.cont.achieve8.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve8.gotoAndStop(2);
                }
                this.container.cont.achieve8.icon.gotoAndStop(38);
                this.container.cont.achieve8.nameTXT.text = "睡眼阑珊";
                this.container.cont.achieve8.noteTXT.text = "伙计要起床";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_07)
                {
                    this.container.cont.achieve9.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve9.gotoAndStop(2);
                }
                this.container.cont.achieve9.icon.gotoAndStop(39);
                this.container.cont.achieve9.nameTXT.text = "超级女声";
                this.container.cont.achieve9.noteTXT.text = "一跃入井";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_08)
                {
                    this.container.cont.achieve10.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve10.gotoAndStop(2);
                }
                this.container.cont.achieve10.icon.gotoAndStop(40);
                this.container.cont.achieve10.nameTXT.text = "老烟枪";
                this.container.cont.achieve10.noteTXT.text = "牛仔和仙人掌";
                this.container.cont.fire4.visible = true;
                this.container.cont.fire4Case.buttonMode = false;
            }
            else if (param1 == 5)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_09)
                {
                    this.container.cont.achieve1.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve1.gotoAndStop(2);
                }
                this.container.cont.achieve1.icon.gotoAndStop(41);
                this.container.cont.achieve1.nameTXT.text = "渔夫";
                this.container.cont.achieve1.noteTXT.text = "小鱼钓渔夫【U77总有好游戏】";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_10)
                {
                    this.container.cont.achieve2.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve2.gotoAndStop(2);
                }
                this.container.cont.achieve2.icon.gotoAndStop(42);
                this.container.cont.achieve2.nameTXT.text = "决斗";
                this.container.cont.achieve2.noteTXT.text = "Injun 杀了牛仔";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_11)
                {
                    this.container.cont.achieve3.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve3.gotoAndStop(2);
                }
                this.container.cont.achieve3.icon.gotoAndStop(43);
                this.container.cont.achieve3.nameTXT.text = "萨满";
                this.container.cont.achieve3.noteTXT.text = "伙计要召唤闪电";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_12)
                {
                    this.container.cont.achieve4.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve4.gotoAndStop(2);
                }
                this.container.cont.achieve4.icon.gotoAndStop(44);
                this.container.cont.achieve4.nameTXT.text = "疯狂射手";
                this.container.cont.achieve4.noteTXT.text = "牛仔开始射击";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_13)
                {
                    this.container.cont.achieve5.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve5.gotoAndStop(2);
                }
                this.container.cont.achieve5.icon.gotoAndStop(45);
                this.container.cont.achieve5.nameTXT.text = "勇猛大头";
                this.container.cont.achieve5.noteTXT.text = "扒光羽毛";
                if (Main.mainClass.saveBoxClass.gameSave.data.achieve_dude_14)
                {
                    this.container.cont.achieve6.gotoAndStop(1);
                }
                else
                {
                    this.container.cont.achieve6.gotoAndStop(2);
                }
                this.container.cont.achieve6.icon.gotoAndStop(46);
                this.container.cont.achieve6.nameTXT.text = "寻路无门";
                this.container.cont.achieve6.noteTXT.text = "伙计应该要坠落深渊";
                this.container.cont.achieve7.visible = false;
                this.container.cont.achieve8.visible = false;
                this.container.cont.achieve9.visible = false;
                this.container.cont.achieve10.visible = false;
                this.container.cont.fire5.visible = true;
                this.container.cont.fire5Case.buttonMode = false;
            }
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(this.mouseX, this.mouseY);
            this.autoguidesObject = null;
            this.autoguidesObject_pt = this.container.cont.btnClose.localToGlobal(new Point(this.container.cont.btnClose.closeCase.x, this.container.cont.btnClose.closeCase.y));
            this.autoguidesObjectWidth = this.container.cont.btnClose.closeCase.width / 2;
            this.autoguidesObjectHeight = this.container.cont.btnClose.closeCase.height / 2;
            if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
            {
                this.autoguidesObject = this.container.cont.btnClose.closeCase;
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
                this.container.cont.mouseChildren = false;
                this.container.cont.mouseEnabled = _loc_1;
                Main.mainClass.levelsMenuClass.container.achieves.gotoAndStop(1);
                this.stage.frameRate = 60;
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                Main.mainClass.levelsMenuClass.removeChild(Main.mainClass.levelsMenuClass.achievementsClass);
                Main.mainClass.levelsMenuClass.achievementsClass = null;
                Main.mainClass.levelsMenuClass.manageListeners("on");
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

    }
}
