 
#include "Achievements.h"   
#include "engine/World.h"   

 
namespace screens
{   
    Achievements_mc::Achievements_mc()
    {
        return;
    }// end function
     

    Achievements::Achievements():frameCounter(0),openFlag(true),fireFrame(0),closeFlag(false),dead(false),container(0)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool Achievements::init(float dt)
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //this->stage.frameRate = 60;
        Main::mainClass->levelsMenuClass->manageListeners("off");
        this->container = new Achievements_mc();
        this->container->stop();
        this->container->back->stop();
        this->container->back->backCase->stop();
        this->container->back->backCase->buttonMode = true;
        this->container->cont->stop();
        this->container->cont->achieve1->stop();
        this->container->cont->achieve2->stop();
        this->container->cont->achieve3->stop();
        this->container->cont->achieve4->stop();
        this->container->cont->achieve5->stop();
        this->container->cont->achieve6->stop();
        this->container->cont->achieve7->stop();
        this->container->cont->achieve8->stop();
        this->container->cont->achieve9->stop();
        this->container->cont->achieve10->stop();
        this->container->cont->btnBack->stop();
        this->container->cont->btnBack->arrowCase->stop();
        this->container->cont->btnForward->stop();
        this->container->cont->btnForward->arrowCase->stop();
        this->container->cont->btnClose->stop();
        this->container->cont->btnClose->closeCase->stop();
        this->container->cont->fire1->stop();
        this->container->cont->fire2->stop();
        this->container->cont->fire3->stop();
        this->container->cont->fire4->stop();
        this->container->cont->fire5->stop();
        this->container->cont->fire1Case->stop();
        this->container->cont->fire2Case->stop();
        this->container->cont->fire3Case->stop();
        this->container->cont->fire4Case->stop();
        this->container->cont->fire5Case->stop();
        this->container->cont->btnBack->arrowCase->buttonMode = true;
        this->container->cont->btnForward->arrowCase->buttonMode = true;
        this->container->cont->btnClose->closeCase->buttonMode = true;
        this->pageManage(1); 
        this->container->cont->mouseChildren = false;
        this->container->cont->mouseEnabled = false;
        this->addChild(this->container);
        //Sounds.instance.playSound("snd_menu_openBoard");
        return true;
    }// end function

    void Achievements::enterFrameHandler(float dt)
    {
        if (this->frameCounter < 30)
        {
            this->frameCounter++;
        }
        else
        {
            this->frameCounter = 1;
        }
        if (this->openFlag)
        {
            if (this->container->currentFrame < this->container->totalFrames)
            {
                this->container->gotoAndStop((this->container->currentFrame + 1));
            }
            else
            {
                this->openFlag = false; 
                this->container->cont->mouseChildren = true;
                this->container->cont->mouseEnabled = true;
                this->autoguidersButtons();
                //this->stage.frameRate = 30;
            }
        }
        else if (this->closeFlag)
        {
            if (this->container->currentFrame > 1)
            {
                this->container->gotoAndStop((this->container->currentFrame - 1));
            }
            else
            {
                this->closeFlag = false;
                this->kill();
            }
        }
        if (this->container->cont->fire1->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire1->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire1->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire2->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire2->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire2->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire3->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire3->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire3->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire4->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire4->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire4->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire5->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire5->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire5->gotoAndStop(this->fireFrame);
        }
        return;
    }// end function

    void Achievements::mouseMoveHandler(param1)
    {
        if (param1->target->name == "backCase")
        {
            if (this->container->back->currentFrame == 1)
            {
                this->container->back->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->back->currentFrame == 2)
        {
            this->container->back->gotoAndStop(1);
        }
        if (param1->target->name == "closeCase")
        {
            if (this->container->cont->btnClose->currentFrame == 1)
            {
                this->container->cont->btnClose->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->btnClose->currentFrame == 2)
        {
            this->container->cont->btnClose->gotoAndStop(1);
        }
        if (param1->target->parent.name == "btnBack")
        {
            if (this->container->cont->btnBack->currentFrame == 1)
            {
                this->container->cont->btnBack->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->btnBack->currentFrame == 2)
        {
            this->container->cont->btnBack->gotoAndStop(1);
        }
        if (param1->target->parent.name == "btnForward")
        {
            if (this->container->cont->btnForward->currentFrame == 1)
            {
                this->container->cont->btnForward->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->btnForward->currentFrame == 2)
        {
            this->container->cont->btnForward->gotoAndStop(1);
        }
        if (param1->target->name == "fire1Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->fire1Case->mouseMoveFlag)
        {
            this->container->cont->fire1Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire2Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->fire2Case->mouseMoveFlag)
        {
            this->container->cont->fire2Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire3Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->fire3Case->mouseMoveFlag)
        {
            this->container->cont->fire3Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire4Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->fire4Case->mouseMoveFlag)
        {
            this->container->cont->fire4Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire5Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->fire5Case->mouseMoveFlag)
        {
            this->container->cont->fire5Case->mouseMoveFlag = false;
        }
        return;
    }// end function

    void Achievements::mouseDownHandler(cocos2d::EventMouse * event)
    {
        if (!this->openFlag)
        {
            if (event->target->name == "backCase")
            {
                if (this->container->back->currentFrame == 2)
                {
                    this->container->back->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "closeCase")
            {
                if (this->container->cont->btnClose->currentFrame == 2)
                {
                    this->container->cont->btnClose->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.parent.name == "btnBack")
            {
                if (this->container->cont->btnBack->currentFrame == 2)
                {
                    this->container->cont->btnBack->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.parent.name == "btnForward")
            {
                if (this->container->cont->btnForward->currentFrame == 2)
                {
                    this->container->cont->btnForward->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "fire1Case")
            {
                if (this->container->cont->fire1Case->buttonMode)
                {
                    this->pageManage(1);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "fire2Case")
            {
                if (this->container->cont->fire2Case->buttonMode)
                {
                    this->pageManage(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "fire3Case")
            {
                if (this->container->cont->fire3Case->buttonMode)
                {
                    this->pageManage(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "fire4Case")
            {
                if (this->container->cont->fire4Case->buttonMode)
                {
                    this->pageManage(4);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "fire5Case")
            {
                if (this->container->cont->fire5Case->buttonMode)
                {
                    this->pageManage(5);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "shadow")
            {
                this->close();
            }
        }
        return;
    }// end function

    void Achievements::mouseUpHandler(cocos2d::EventMouse * event) 
    {
        if (event->target->name == "backCase")
        {
            if (this->container->back->currentFrame == 3)
            {
                this->container->back->gotoAndStop(2);
                this->close();
            }
        }
        else if (this->container->back->currentFrame == 3)
        {
            this->container->back->gotoAndStop(1);
        }
        if (event->target->name == "closeCase")
        {
            if (this->container->cont->btnClose->currentFrame == 3)
            {
                this->container->cont->btnClose->gotoAndStop(2);
                this->close();
            }
        }
        else if (this->container->cont->btnClose->currentFrame == 3)
        {
            this->container->cont->btnClose->gotoAndStop(1);
        }
        if (event.target.parent.name == "btnBack")
        {
            if (this->container->cont->btnBack->currentFrame == 3)
            {
                this->container->cont->btnBack->gotoAndStop(2);
                this->pageManage((this->page - 1));
            }
        }
        else if (this->container->cont->btnBack->currentFrame == 3)
        {
            this->container->cont->btnBack->gotoAndStop(1);
        }
        if (event.target.parent.name == "btnForward")
        {
            if (this->container->cont->btnForward->currentFrame == 3)
            {
                this->container->cont->btnForward->gotoAndStop(2);
                this->pageManage((this->page + 1));
            }
        }
        else if (this->container->cont->btnForward->currentFrame == 3)
        {
            this->container->cont->btnForward->gotoAndStop(1);
        }
        return;
    }// end function

    void Achievements::pageManage(int param1)  
    {
        if (param1 < 1)
        {
            param1 = 5;
        }
        else if (param1 > 5)
        {
            param1 = 1;
        }
        this->page = param1;
        if (!this->container->cont->achieve1->isVisible())
        {
            this->container->cont->achieve1->setVisible(true);
        }
        if (!this->container->cont->achieve2->isVisible())
        {
            this->container->cont->achieve2->setVisible(true);
        }
        if (!this->container->cont->achieve3->isVisible())
        {
            this->container->cont->achieve3->setVisible(true);
        }
        if (!this->container->cont->achieve4->isVisible())
        {
            this->container->cont->achieve4->setVisible(true);
        }
        if (!this->container->cont->achieve5->isVisible())
        {
            this->container->cont->achieve5->setVisible(true);
        }
        if (!this->container->cont->achieve6->isVisible())
        {
            this->container->cont->achieve6->setVisible(true);
        }
        if (!this->container->cont->achieve7->isVisible())
        {
            this->container->cont->achieve7->setVisible(true);
        }
        if (!this->container->cont->achieve8->isVisible())
        {
            this->container->cont->achieve8->setVisible(true);
        }
        if (!this->container->cont->achieve9->isVisible())
        {
            this->container->cont->achieve9->setVisible(true);
        }
        if (!this->container->cont->achieve10->isVisible())
        {
            this->container->cont->achieve10->setVisible(true);
        }
        if (this->container->cont->fire1->isVisible())
        {
            this->container->cont->fire1->setVisible(false);
        }
        if (this->container->cont->fire2->isVisible())
        {
            this->container->cont->fire2->setVisible(false);
        }
        if (this->container->cont->fire3->isVisible())
        {
            this->container->cont->fire3->setVisible(false);
        }
        if (this->container->cont->fire4->isVisible())
        {
            this->container->cont->fire4->setVisible(false);
        }
        if (this->container->cont->fire5->isVisible())
        {
            this->container->cont->fire5->setVisible(false);
        }
        if (!this->container->cont->fire1Case->buttonMode)
        {
            this->container->cont->fire1Case->buttonMode = true;
        }
        if (!this->container->cont->fire2Case->buttonMode)
        {
            this->container->cont->fire2Case->buttonMode = true;
        }
        if (!this->container->cont->fire3Case->buttonMode)
        {
            this->container->cont->fire3Case->buttonMode = true;
        }
        if (!this->container->cont->fire4Case->buttonMode)
        {
            this->container->cont->fire4Case->buttonMode = true;
        }
        if (!this->container->cont->fire5Case->buttonMode)
        {
            this->container->cont->fire5Case->buttonMode = true;
        }
        if (param1 == 1)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_firstKill"))
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(1);
            std::setText(this->container->cont->achieve1->nameTxt,"第一滴血");
            std::setText(this->container->cont->achieve1->noteTxt,"杀死 1 名敌人【U77总有好游戏】");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_kill_100_enemies")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(2);
            std::setText(this->container->cont->achieve2->nameTxt,"热烈无比");
            std::setText(this->container->cont->achieve2->noteTxt,"在一场游戏中杀死 100 名敌人");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_kill_2500_enemies")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(3);
            std::setText(this->container->cont->achieve3->nameTxt,"杀手");
            std::setText(this->container->cont->achieve3->noteTxt,"杀死 2500 名敌人");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_call_100_earlyWaves")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(4);
            std::setText(this->container->cont->achieve4->nameTxt,"毫无畏惧");
            std::setText(this->container->cont->achieve4->noteTxt,"提前召唤 100 波次");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_build_100_towers")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(5);
            std::setText(this->container->cont->achieve5->nameTxt,"建造者");
            std::setText(this->container->cont->achieve5->noteTxt,"建造 100 座塔楼");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createGolem_5_times")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(6);
            std::setText(this->container->cont->achieve6->nameTxt,"巨型支援");
            std::setText(this->container->cont->achieve6->noteTxt,"一场任务中召唤 5 次击碎者");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createIceman_15_times")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(7);
            std::setText(this->container->cont->achieve7->nameTxt,"缓和");
            std::setText(this->container->cont->achieve7->noteTxt,"一场任务中召唤 15 次冰冻者");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createAir_7_times")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(8);
            std::setText(this->container->cont->achieve8->nameTxt,"远古支援");
            std::setText(this->container->cont->achieve8->noteTxt,"一场任务中召唤 7 次复活岛巨像");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_callAllWavesInLevel")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(9);
            std::setText(this->container->cont->achieve9->nameTxt,"大胆");
            std::setText(this->container->cont->achieve9->noteTxt,"一场任务中提前召唤所有波次");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellFireIceStoneLevin")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(10);
            std::setText(this->container->cont->achieve10->nameTxt,"破坏者");
            std::setText(this->container->cont->achieve10->noteTxt,"一场任务中出售所有类型元素");
            this->container->cont->fire1->setVisible(true);
            this->container->cont->fire1Case->buttonMode = false;
        }
        else if (param1 == 2)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellFire_10_times")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(11);
            std::setText(this->container->cont->achieve1->nameTxt,"火焰破坏者");
            std::setText(this->container->cont->achieve1->noteTxt,"出售 10 次火焰元素【U 7 7 汉化】");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellIce_10_times")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(12);
            std::setText(this->container->cont->achieve2->nameTxt,"寒冰破坏者");
            std::setText(this->container->cont->achieve2->noteTxt,"出售 10 次寒冰元素");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellStone_10_times")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(13);
            std::setText(this->container->cont->achieve3->nameTxt,"巨石破坏者");
            std::setText(this->container->cont->achieve3->noteTxt,"出售 10 次岩石元素");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellLevin_10_times")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(14);
            std::setText(this->container->cont->achieve4->nameTxt,"闪电破坏者");
            std::setText(this->container->cont->achieve4->noteTxt,"出售 10 次闪电元素");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_golemKill_250_enemies")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(15);
            std::setText(this->container->cont->achieve5->nameTxt,"粉碎者");
            std::setText(this->container->cont->achieve5->noteTxt,"击碎者碾碎 250 个大头");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_icemanSlowdown_75_enemies")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(16);
            std::setText(this->container->cont->achieve6->nameTxt,"有点冷");
            std::setText(this->container->cont->achieve6->noteTxt,"一场任务中冰冻 75 个单位");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_icemanSlowdown_500_enemies")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(17);
            std::setText(this->container->cont->achieve7->nameTxt,"霜冻力量");
            std::setText(this->container->cont->achieve7->noteTxt,"冰冻者冰冻 500 个大头");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildUltraTower")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(18);
            std::setText(this->container->cont->achieve8->nameTxt,"进阶建造者");
            std::setText(this->container->cont->achieve8->noteTxt,"建造 1 座超级塔楼");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildUltraTower_50_times")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(19);
            std::setText(this->container->cont->achieve9->nameTxt,"专家建造者");
            std::setText(this->container->cont->achieve9->noteTxt,"建造 50 座超级塔楼");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildAllUltraTowers")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(20);
            std::setText(this->container->cont->achieve10->nameTxt,"策略建造者");
            std::setText(this->container->cont->achieve10->noteTxt,"一场游戏中每种类型建造一座超级塔楼总计 4 座");
            this->container->cont->fire2->setVisible(true);
            this->container->cont->fire2Case->buttonMode = false;
        }
        else if (param1 == 3)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_notCast")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(21);
            std::setText(this->container->cont->achieve1->nameTxt,"上手");
            std::setText(this->container->cont->achieve1->noteTxt,"一场游戏中不召唤任何元素法术【U77总有好游戏】");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castFire_150_times")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(22);
            std::setText(this->container->cont->achieve2->nameTxt,"火焰大师");
            std::setText(this->container->cont->achieve2->noteTxt,"召唤 150 次火焰元素");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castIce_150_times")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(23);
            std::setText(this->container->cont->achieve3->nameTxt,"寒冰大师");
            std::setText(this->container->cont->achieve3->noteTxt,"召唤 150 次寒冰元素");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castStone_150_times")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(24);
            std::setText(this->container->cont->achieve4->nameTxt,"岩石大师");
            std::setText(this->container->cont->achieve4->noteTxt,"召唤 150 次岩石元素");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castLevin_150_times")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(25);
            std::setText(this->container->cont->achieve5->nameTxt,"闪电大师");
            std::setText(this->container->cont->achieve5->noteTxt,"召唤 150 次闪电元素");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castGetAll_10_times")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(26);
            std::setText(this->container->cont->achieve6->nameTxt,"策略爆破者");
            std::setText(this->container->cont->achieve6->noteTxt,"一场游戏中召唤 10 次超级噼里啪啦");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castGetAll_100_times")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(27);
            std::setText(this->container->cont->achieve7->nameTxt,"爆破者");
            std::setText(this->container->cont->achieve7->noteTxt,"召唤 100 次超级噼里啪啦");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castKill_1_enemy")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(28);
            std::setText(this->container->cont->achieve8->nameTxt,"施法者");
            std::setText(this->container->cont->achieve8->noteTxt,"召唤任意元素杀死 1 名敌人");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castKill_100_enemy")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(29);
            std::setText(this->container->cont->achieve9->nameTxt,"法术杀手");
            std::setText(this->container->cont->achieve9->noteTxt,"召唤任意元素杀死 150 名敌人");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_hardLevels")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(30);
            std::setText(this->container->cont->achieve10->nameTxt,"勇猛战士");
            std::setText(this->container->cont->achieve10->noteTxt,"困难难度下通过 10 关");
            this->container->cont->fire3->setVisible(true);
            this->container->cont->fire3Case->buttonMode = false;
        }
        else if (param1 == 4)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_survivalLevels")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(31);
            std::setText(this->container->cont->achieve1->nameTxt,"幸存者");
            std::setText(this->container->cont->achieve1->noteTxt,"生存关卡通过 10 关【U 7 7 汉化】");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_withAllLives")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(32);
            std::setText(this->container->cont->achieve2->nameTxt,"活力四射");
            std::setText(this->container->cont->achieve2->noteTxt,"不损失生命值通过 10 关");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_01")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(33);
            std::setText(this->container->cont->achieve3->nameTxt,"伐木工");
            std::setText(this->container->cont->achieve3->noteTxt,"伙计去伐木");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_02")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(34);
            std::setText(this->container->cont->achieve4->nameTxt,"忙忙碌碌");
            std::setText(this->container->cont->achieve4->noteTxt,"伙计走开");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_03")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(35);
            std::setText(this->container->cont->achieve5->nameTxt,"南瓜节");
            std::setText(this->container->cont->achieve5->noteTxt,"失掉 3 个南瓜");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_04")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(36);
            std::setText(this->container->cont->achieve6->nameTxt,"修理工");
            std::setText(this->container->cont->achieve6->noteTxt,"打到伙计的手指");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_05")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(37);
            std::setText(this->container->cont->achieve7->nameTxt,"勇士");
            std::setText(this->container->cont->achieve7->noteTxt,"伙计跑到森林里");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_06")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(38);
            std::setText(this->container->cont->achieve8->nameTxt,"睡眼阑珊");
            std::setText(this->container->cont->achieve8->noteTxt,"伙计要起床");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_07")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(39);
            std::setText(this->container->cont->achieve9->nameTxt,"超级女声");
            std::setText(this->container->cont->achieve9->noteTxt,"一跃入井");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_08")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(40);
            std::setText(this->container->cont->achieve10->nameTxt,"老烟枪");
            std::setText(this->container->cont->achieve10->noteTxt,"牛仔和仙人掌");
            this->container->cont->fire4->setVisible(true);
            this->container->cont->fire4Case->buttonMode = false;
        }
        else if (param1 == 5)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_09")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(41);
            std::setText(this->container->cont->achieve1->nameTxt,"渔夫");
            std::setText(this->container->cont->achieve1->noteTxt,"小鱼钓渔夫【U77总有好游戏】");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_10")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(42);
            std::setText(this->container->cont->achieve2->nameTxt,"决斗");
            std::setText(this->container->cont->achieve2->noteTxt,"Injun 杀了牛仔");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_11")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(43);
            std::setText(this->container->cont->achieve3->nameTxt,"萨满");
            std::setText(this->container->cont->achieve3->noteTxt,"伙计要召唤闪电");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_12")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(44);
            std::setText(this->container->cont->achieve4->nameTxt,"疯狂射手");
            std::setText(this->container->cont->achieve4->noteTxt,"牛仔开始射击");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_13")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(45);
            std::setText(this->container->cont->achieve5->nameTxt,"勇猛大头");
            std::setText(this->container->cont->achieve5->noteTxt,"扒光羽毛");
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_14")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(46);
            std::setText(this->container->cont->achieve6->nameTxt,"寻路无门");
            std::setText(this->container->cont->achieve6->noteTxt,"伙计应该要坠落深渊");
            this->container->cont->achieve7->setVisible(false);
            this->container->cont->achieve8->setVisible(false);
            this->container->cont->achieve9->setVisible(false);
            this->container->cont->achieve10->setVisible(false);
            this->container->cont->fire5->setVisible(true);
            this->container->cont->fire5Case->buttonMode = false;
        }
        return;
    }// end function

    void Achievements::autoguidersButtons()  
    {
        this->autoguidesMouse_pt = cocos2d::Point(this->mouseX, this->mouseY);
        this->autoguidesObject = NULL;
        this->autoguidesObject_pt = this->container->cont->btnClose->localToGlobal(this->container->cont->btnClose->closeCase->getPosition());
        this->autoguidesObjectWidth = this->container->cont->btnClose->closeCase.width / 2;
        this->autoguidesObjectHeight = this->container->cont->btnClose->closeCase.height / 2;
        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        {
            this->autoguidesObject = this->container->cont->btnClose->closeCase;
        }
        if (this->autoguidesObject)
        {
            this->tempObject = new Object();
            this->tempObject.target = this->autoguidesObject;
            this->mouseMoveHandler(this->tempObject);
        }
        return;
    }// end function

    void Achievements::close()  
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true; 
            this->container->cont->mouseChildren = false;
            this->container->cont->mouseEnabled = false;
            Main::mainClass->levelsMenuClass->container->achieves->gotoAndStop(1);
            //this->stage.frameRate = 60;
        }
        return;
    }// end function

    void Achievements::kill()  
    {
        if (!this->dead)
        {
            this->dead = true;
            Main::mainClass->levelsMenuClass->removeChild(Main::mainClass->levelsMenuClass->achievementsClass);
            Main::mainClass->levelsMenuClass->achievementsClass = NULL;
            Main::mainClass->levelsMenuClass->manageListeners("on");
        }
        return;
    }// end function

   // void Achievements::reInit(event:Event)  
   // {
   //     this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
   //     this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
   //     this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
   //     this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
   //     this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
   //     this->stage.frameRate = 30;
   //     return;
   // }// end function
 
}
