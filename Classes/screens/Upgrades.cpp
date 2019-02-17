#include "Upgrades.h"   
#include "MainClass.h"
#include "LevelsMenu.h"
namespace screens
{   
    Upgrades_mc::Upgrades_mc()
    {
        return;
    };// end function
    HintUpgrade_mc::HintUpgrade_mc()
    {
        return;
    };
    
     

    Upgrades::Upgrades():frameCounter(0),openFlag(true),closeFlag(false), dead(false), costGolemUpgrade1(2),costGolemUpgrade2(2),costGolemUpgrade3(2)
        ,costGolemUpgrade4(3),costGolemUpgrade5(4),costIcemanUpgrade1(1),costIcemanUpgrade2(2),costIcemanUpgrade3(2),costIcemanUpgrade4(3),
        costIcemanUpgrade5(4),costAirUpgrade1(1),costAirUpgrade2(2),costAirUpgrade3(2),costAirUpgrade4(3),costAirUpgrade5(4),costFireUpgrade1(1),
        costFireUpgrade2(1),costFireUpgrade3(1),costFireUpgrade4(1),costFireUpgrade5(2),costIceUpgrade1(1),costIceUpgrade2(1),costIceUpgrade3(1),
        costIceUpgrade4(1),costIceUpgrade5(2),costStoneUpgrade1(1),costStoneUpgrade2(1),costStoneUpgrade3(1),costStoneUpgrade4(1),costStoneUpgrade5(2),
        costLevinUpgrade1(1),costLevinUpgrade2(1),costLevinUpgrade3(2),costLevinUpgrade4(2),costLevinUpgrade5(2),
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool Upgrades::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->stage.frameRate = 60;
        this->levelsMenu = Main::mainClass->levelsMenuClass;
        this->levelsMenu->manageListeners("off");
        this->manageListeners("on");
        this->container = new Upgrades_mc();
        this->container->stop();
        this->container->back->stop();
        this->container->back->backCase->stop();
        this->container->back->backCase->setMouseEnabled(true);
        this->container->cont->stop();
        this->container->cont->btnReset->stop();
        this->container->cont->btnAccept->stop();
        this->container->cont->golemArrow1->stop();
        this->container->cont->golemArrow2->stop();
        this->container->cont->golemArrow3->stop();
        this->container->cont->golemArrow4->stop();
        this->container->cont->icemanArrow1->stop();
        this->container->cont->icemanArrow2->stop();
        this->container->cont->icemanArrow3->stop();
        this->container->cont->icemanArrow4->stop();
        this->container->cont->airArrow1->stop();
        this->container->cont->airArrow2->stop();
        this->container->cont->airArrow3->stop();
        this->container->cont->airArrow4->stop();
        this->container->cont->fireArrow1->stop();
        this->container->cont->fireArrow2->stop();
        this->container->cont->fireArrow3->stop();
        this->container->cont->fireArrow4->stop();
        this->container->cont->iceArrow1->stop();
        this->container->cont->iceArrow2->stop();
        this->container->cont->iceArrow3->stop();
        this->container->cont->iceArrow4->stop();
        this->container->cont->stoneArrow1->stop();
        this->container->cont->stoneArrow2->stop();
        this->container->cont->stoneArrow3->stop();
        this->container->cont->stoneArrow4->stop();
        this->container->cont->levinArrow1->stop();
        this->container->cont->levinArrow2->stop();
        this->container->cont->levinArrow3->stop();
        this->container->cont->levinArrow4->stop();
        this->container->cont->btnReset->resetCase->setMouseEnabled(true);
        this->container->cont->btnAccept->acceptCase->setMouseEnabled(true);
        this->container->cont->golemArrow1->setVisible(false);
        this->container->cont->golemArrow2->setVisible(false);
        this->container->cont->golemArrow3->setVisible(false);
        this->container->cont->golemArrow4->setVisible(false);
        this->container->cont->icemanArrow1->setVisible(false);
        this->container->cont->icemanArrow2->setVisible(false);
        this->container->cont->icemanArrow3->setVisible(false);
        this->container->cont->icemanArrow4->setVisible(false);
        this->container->cont->airArrow1->setVisible(false);
        this->container->cont->airArrow2->setVisible(false);
        this->container->cont->airArrow3->setVisible(false);
        this->container->cont->airArrow4->setVisible(false);
        this->container->cont->fireArrow1->setVisible(false);
        this->container->cont->fireArrow2->setVisible(false);
        this->container->cont->fireArrow3->setVisible(false);
        this->container->cont->fireArrow4->setVisible(false);
        this->container->cont->iceArrow1->setVisible(false);
        this->container->cont->iceArrow2->setVisible(false);
        this->container->cont->iceArrow3->setVisible(false);
        this->container->cont->iceArrow4->setVisible(false);
        this->container->cont->stoneArrow1->setVisible(false);
        this->container->cont->stoneArrow2->setVisible(false);
        this->container->cont->stoneArrow3->setVisible(false);
        this->container->cont->stoneArrow4->setVisible(false);
        this->container->cont->levinArrow1->setVisible(false);
        this->container->cont->levinArrow2->setVisible(false);
        this->container->cont->levinArrow3->setVisible(false);
        this->container->cont->levinArrow4->setVisible(false);
        this->addChild(this->container);
        this->hint = new HintUpgrade_mc();
        this->hint->stop();
        this->hint->myTarget = NULL; 
        this->hint->setMouseChildren(false);
        this->hint->setMouseEnabled(false);
        this->hint->setVisible(false);
        this->addChild(this->hint);
        this->upgradeUpdate(); 
        this->container->cont->setMouseChildren(false);
        this->container->cont->setMouseEnabled(false);
        AudioUtil::playSound("Snd_menu_openBoard.mp3");
        return;
    }// end function

    void Upgrades::enterFrameHandler(cocos2d::EventMouse * event)
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
                this->container->cont->setMouseChildren(true);
                this->container->cont->setMouseEnabled(true);
                this->upgradeUpdate();
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
        if (this->listOfUpgradeAnima.size() > 0)
        {
            this->i = this->listOfUpgradeAnima.size() - 1;
            while (this->i >= 0)
            { 
                if (this->listOfUpgradeAnima[this->i]->currentFrame < this->listOfUpgradeAnima[this->i]->totalFrames)
                {
                    this->listOfUpgradeAnima[this->i]->gotoAndStop((this->listOfUpgradeAnima[this->i]->currentFrame + 1));
                }
                else
                {
                    this->removeChild(this->listOfUpgradeAnima[this->i]);
                    this->listOfUpgradeAnima.splice(this->i, 1);
                }
                i--;
            }
        }
        if (this->hint->isVisible())
        {
            this->hint->setPosition(this->mouseX,this->mouseY);
        }
        this->setChildIndex(this->hint, (this->numChildren - 1));
        return;
    }// end function

    void Upgrades::mouseMoveHandler(cocos2d::EventMouse * e)
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (targetName == "backCase")
        {
            if (this->container->back->currentFrame == 1)
            {
                this->container->back->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->back->currentFrame == 2)
        {
            this->container->back->gotoAndStop(1);
        }
        if (targetName == "resetCase")
        {
            if (this->container->cont->btnReset->currentFrame == 1)
            {
                this->container->cont->btnReset->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->btnReset->currentFrame == 2)
        {
            this->container->cont->btnReset->gotoAndStop(1);
        }
        if (targetName == "acceptCase")
        {
            if (this->container->cont->btnAccept->currentFrame == 1)
            {
                this->container->cont->btnAccept->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->btnAccept->currentFrame == 2)
        {
            this->container->cont->btnAccept->gotoAndStop(1);
        }
        if (targetName == "upgradeCase")
        {
            if (this->nowUpgradeButton)
            {
                if (this->nowUpgradeButton != event.target.parent)
                {
                    if (this->nowUpgradeButton->currentFrame == 2)
                    {
                        tempObject = this->nowUpgradeButton->starsTXT.text;
                        this->nowUpgradeButton->gotoAndStop(1);
                        std::setText(this->nowUpgradeButton->starsTXT,tempObject);
                        this->nowUpgradeButton->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                    }
                }
            }
            this->nowUpgradeButton = event.target.parent;
            if (this->nowUpgradeButton->currentFrame == 1)
            {
                tempObject = this->nowUpgradeButton->starsTXT.text;
                this->nowUpgradeButton->gotoAndStop(2);
                std::setText(this->nowUpgradeButton->starsTXT,tempObject);
                this->nowUpgradeButton->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
            if (!this->hint->isVisible() || this->hint->myTarget != this->nowUpgradeButton)
            {
                this->hint->setVisible(true);
                this->hint->myTarget = this->nowUpgradeButton;
                if (this->hint->myTarget.name == "golemUpgrade1")
                {
                    this->hint->gotoAndStop(1);
                }
                else if (this->hint->myTarget.name == "golemUpgrade2")
                {
                    this->hint->gotoAndStop(2);
                }
                else if (this->hint->myTarget.name == "golemUpgrade3")
                {
                    this->hint->gotoAndStop(3);
                }
                else if (this->hint->myTarget.name == "golemUpgrade4")
                {
                    this->hint->gotoAndStop(4);
                }
                else if (this->hint->myTarget.name == "golemUpgrade5")
                {
                    this->hint->gotoAndStop(5);
                }
                else if (this->hint->myTarget.name == "icemanUpgrade1")
                {
                    this->hint->gotoAndStop(6);
                }
                else if (this->hint->myTarget.name == "icemanUpgrade2")
                {
                    this->hint->gotoAndStop(7);
                }
                else if (this->hint->myTarget.name == "icemanUpgrade3")
                {
                    this->hint->gotoAndStop(8);
                }
                else if (this->hint->myTarget.name == "icemanUpgrade4")
                {
                    this->hint->gotoAndStop(9);
                }
                else if (this->hint->myTarget.name == "icemanUpgrade5")
                {
                    this->hint->gotoAndStop(10);
                }
                else if (this->hint->myTarget.name == "airUpgrade1")
                {
                    this->hint->gotoAndStop(11);
                }
                else if (this->hint->myTarget.name == "airUpgrade2")
                {
                    this->hint->gotoAndStop(12);
                }
                else if (this->hint->myTarget.name == "airUpgrade3")
                {
                    this->hint->gotoAndStop(13);
                }
                else if (this->hint->myTarget.name == "airUpgrade4")
                {
                    this->hint->gotoAndStop(14);
                }
                else if (this->hint->myTarget.name == "airUpgrade5")
                {
                    this->hint->gotoAndStop(15);
                }
                else if (this->hint->myTarget.name == "fireUpgrade1")
                {
                    this->hint->gotoAndStop(16);
                }
                else if (this->hint->myTarget.name == "fireUpgrade2")
                {
                    this->hint->gotoAndStop(17);
                }
                else if (this->hint->myTarget.name == "fireUpgrade3")
                {
                    this->hint->gotoAndStop(18);
                }
                else if (this->hint->myTarget.name == "fireUpgrade4")
                {
                    this->hint->gotoAndStop(19);
                }
                else if (this->hint->myTarget.name == "fireUpgrade5")
                {
                    this->hint->gotoAndStop(20);
                }
                else if (this->hint->myTarget.name == "iceUpgrade1")
                {
                    this->hint->gotoAndStop(21);
                }
                else if (this->hint->myTarget.name == "iceUpgrade2")
                {
                    this->hint->gotoAndStop(22);
                }
                else if (this->hint->myTarget.name == "iceUpgrade3")
                {
                    this->hint->gotoAndStop(23);
                }
                else if (this->hint->myTarget.name == "iceUpgrade4")
                {
                    this->hint->gotoAndStop(24);
                }
                else if (this->hint->myTarget.name == "iceUpgrade5")
                {
                    this->hint->gotoAndStop(25);
                }
                else if (this->hint->myTarget.name == "stoneUpgrade1")
                {
                    this->hint->gotoAndStop(26);
                }
                else if (this->hint->myTarget.name == "stoneUpgrade2")
                {
                    this->hint->gotoAndStop(27);
                }
                else if (this->hint->myTarget.name == "stoneUpgrade3")
                {
                    this->hint->gotoAndStop(28);
                }
                else if (this->hint->myTarget.name == "stoneUpgrade4")
                {
                    this->hint->gotoAndStop(29);
                }
                else if (this->hint->myTarget.name == "stoneUpgrade5")
                {
                    this->hint->gotoAndStop(30);
                }
                else if (this->hint->myTarget.name == "levinUpgrade1")
                {
                    this->hint->gotoAndStop(31);
                }
                else if (this->hint->myTarget.name == "levinUpgrade2")
                {
                    this->hint->gotoAndStop(32);
                }
                else if (this->hint->myTarget.name == "levinUpgrade3")
                {
                    this->hint->gotoAndStop(33);
                }
                else if (this->hint->myTarget.name == "levinUpgrade4")
                {
                    this->hint->gotoAndStop(34);
                }
                else if (this->hint->myTarget.name == "levinUpgrade5")
                {
                    this->hint->gotoAndStop(35);
                }
                this->hint->setPosition(  this->mouseX, this->mouseY);
            }
        }
        else if (this->nowUpgradeButton)
        {
            if (this->nowUpgradeButton->currentFrame == 2)
            {
                tempObject = this->nowUpgradeButton->starsTXT.text;
                this->nowUpgradeButton->gotoAndStop(1);
                std::setText(this->nowUpgradeButton->starsTXT,tempObject);
                this->nowUpgradeButton->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            }
            if (this->hint->isVisible())
            {
                this->hint->setVisible(false);
            }
        }
        return;
    }// end function

    void Upgrades::mouseDownHandler(cocos2d::EventMouse * e)
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (!this->openFlag)
        {
            if (targetName == "backCase")
            {
                if (this->container->back->currentFrame == 2)
                {
                    this->container->back->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "resetCase")
            {
                if (this->container->cont->btnReset->currentFrame == 2)
                {
                    this->container->cont->btnReset->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "acceptCase")
            {
                if (this->container->cont->btnAccept->currentFrame == 2)
                {
                    this->container->cont->btnAccept->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "shadow")
            {
                this->close();
            }
            else if (targetName == "upgradeCase")
            {
                if (this->nowUpgradeButton)
                {
                    if (this->nowUpgradeButton != event.target.parent)
                    {
                        if (this->nowUpgradeButton->currentFrame == 2)
                        {
                            this->nowUpgradeButton->gotoAndStop(1);
                        }
                    }
                    if (this->nowUpgradeButton->currentFrame == 2)
                    {
                        this->nowUpgradeButton->gotoAndStop(3);
                        cocos2d::Point tempObject = this->container->cont->localToGlobal(this->nowUpgradeButton->getPosition()));
                        AnimUpgrade_mc * tempObject1 = new AnimUpgrade_mc();
                        tempObject1->stop();
                        tempObject1->setPosition( tempObject); 
                        tempObject1->setMouseChildren(false);
                        tempObject1->setMouseEnabled(false);
                        this->addChild(tempObject1);
                        this->listOfUpgradeAnima.push(tempObject1);
                        AudioUtil::playSound("Snd_menu_upgrIconMouseDown.mp3");
                        int stars=Main::mainClass->saveBoxClass->getIntValue("stars");
                        if (this->nowUpgradeButton->name == "golemUpgrade1")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeGolem1", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costGolemUpgrade1);
                        }
                        else if (this->nowUpgradeButton->name == "golemUpgrade2")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeGolem2", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costGolemUpgrade2);
                        }
                        else if (this->nowUpgradeButton->name == "golemUpgrade3")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeGolem3", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costGolemUpgrade3);
                        }
                        else if (this->nowUpgradeButton->name == "golemUpgrade4")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeGolem4", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costGolemUpgrade4);
                        }
                        else if (this->nowUpgradeButton->name == "golemUpgrade5")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeGolem5", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costGolemUpgrade5);
                        }
                        if (this->nowUpgradeButton->name == "icemanUpgrade1")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIceman1", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIcemanUpgrade1);
                        }
                        else if (this->nowUpgradeButton->name == "icemanUpgrade2")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIceman2", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIcemanUpgrade2);
                        }
                        else if (this->nowUpgradeButton->name == "icemanUpgrade3")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIceman3", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIcemanUpgrade3);
                        }
                        else if (this->nowUpgradeButton->name == "icemanUpgrade4")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIceman4", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIcemanUpgrade4);
                        }
                        else if (this->nowUpgradeButton->name == "icemanUpgrade5")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIceman5", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIcemanUpgrade5);
                        }
                        if (this->nowUpgradeButton->name == "airUpgrade1")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeAir1", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costAirUpgrade1);
                        }
                        else if (this->nowUpgradeButton->name == "airUpgrade2")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeAir2", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costAirUpgrade2);
                        }
                        else if (this->nowUpgradeButton->name == "airUpgrade3")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeAir3", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costAirUpgrade3);
                        }
                        else if (this->nowUpgradeButton->name == "airUpgrade4")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeAir4", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costAirUpgrade4);
                        }
                        else if (this->nowUpgradeButton->name == "airUpgrade5")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeAir5", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costAirUpgrade5);
                        }
                        if (this->nowUpgradeButton->name == "fireUpgrade1")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeFire1", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costFireUpgrade1);
                        }
                        else if (this->nowUpgradeButton->name == "fireUpgrade2")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeFire2", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costFireUpgrade2);
                        }
                        else if (this->nowUpgradeButton->name == "fireUpgrade3")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeFire3", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costFireUpgrade3);
                        }
                        else if (this->nowUpgradeButton->name == "fireUpgrade4")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeFire4", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costFireUpgrade4);
                        }
                        else if (this->nowUpgradeButton->name == "fireUpgrade5")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeFire5", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costFireUpgrade5);
                        }
                        if (this->nowUpgradeButton->name == "iceUpgrade1")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIce1", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIceUpgrade1);
                        }
                        else if (this->nowUpgradeButton->name == "iceUpgrade2")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIce2", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIceUpgrade2);
                        }
                        else if (this->nowUpgradeButton->name == "iceUpgrade3")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIce3", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIceUpgrade3);
                        }
                        else if (this->nowUpgradeButton->name == "iceUpgrade4")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIce4", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIceUpgrade4);
                        }
                        else if (this->nowUpgradeButton->name == "iceUpgrade5")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeIce5", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costIceUpgrade5);
                        }
                        if (this->nowUpgradeButton->name == "stoneUpgrade1")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeStone1", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costStoneUpgrade1);
                        }
                        else if (this->nowUpgradeButton->name == "stoneUpgrade2")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeStone2", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costStoneUpgrade2);
                        }
                        else if (this->nowUpgradeButton->name == "stoneUpgrade3")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeStone3", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costStoneUpgrade3);
                        }
                        else if (this->nowUpgradeButton->name == "stoneUpgrade4")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeStone4", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costStoneUpgrade4);
                        }
                        else if (this->nowUpgradeButton->name == "stoneUpgrade5")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeStone5", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costStoneUpgrade5);
                        }
                        if (this->nowUpgradeButton->name == "levinUpgrade1")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeLevin1", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costLevinUpgrade1);
                        }
                        else if (this->nowUpgradeButton->name == "levinUpgrade2")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeLevin2", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costLevinUpgrade2);
                        }
                        else if (this->nowUpgradeButton->name == "levinUpgrade3")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeLevin3", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costLevinUpgrade3);
                        }
                        else if (this->nowUpgradeButton->name == "levinUpgrade4")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeLevin4", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costLevinUpgrade4);
                        }
                        else if (this->nowUpgradeButton->name == "levinUpgrade5")
                        {
                            Main::mainClass->saveBoxClass->setValue("upgradeLevin5", true);
                            Main::mainClass->saveBoxClass->setValue(stars - this->costLevinUpgrade5);
                        }
                        this->upgradeUpdate();
                    }
                }
            }
        }
        return;
    }// end function

    void Upgrades::mouseUpHandler(cocos2d::EventMouse * e)
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
        string targetName = event->target->getName();
        if (targetName == "backCase")
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
        if (targetName == "resetCase")
        {
            if (this->container->cont->btnReset->currentFrame == 3)
            {
                this->container->cont->btnReset->gotoAndStop(2);
                AudioUtil::playSound("Snd_menu_upgrReset.mp3");
                int stars=Main::mainClass->saveBoxClass->getIntValue("stars");
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem1"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeGolem1", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costGolemUpgrade1);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem2"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeGolem2", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costGolemUpgrade2);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem3"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeGolem3", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costGolemUpgrade3);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem4"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeGolem4", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costGolemUpgrade4);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem5"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeGolem5", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costGolemUpgrade5);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman1"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIceman1", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIcemanUpgrade1);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman2"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIceman2", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIcemanUpgrade2);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman3"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIceman3", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIcemanUpgrade3);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman4"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIceman4", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIcemanUpgrade4);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman5"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIceman5", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIcemanUpgrade5);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir1"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeAir1", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costAirUpgrade1);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir2"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeAir2", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costAirUpgrade2);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir3"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeAir3", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costAirUpgrade3);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir4"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeAir4", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costAirUpgrade4);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir5"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeAir5", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costAirUpgrade5);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire1"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeFire1", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costFireUpgrade1);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire2"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeFire2", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costFireUpgrade2);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire3"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeFire3", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costFireUpgrade3);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire4"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeFire4", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costFireUpgrade4);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire5"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeFire5", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costFireUpgrade5);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce1"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIce1", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIceUpgrade1);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce2"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIce2", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIceUpgrade2);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce3"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIce3", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIceUpgrade3);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce4"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIce4", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIceUpgrade4);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce5"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeIce5", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costIceUpgrade5);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeStone1"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeStone1", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costStoneUpgrade1);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeStone2"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeStone2", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costStoneUpgrade2);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeStone3"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeStone3", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costStoneUpgrade3);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeStone4"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeStone4", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costStoneUpgrade4);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeStone5"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeStone5", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costStoneUpgrade5);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeLevin1"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeLevin1", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costLevinUpgrade1);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeLevin2"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeLevin2", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costLevinUpgrade2);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeLevin3"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeLevin3", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costLevinUpgrade3);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeLevin4"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeLevin4", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costLevinUpgrade4);
                }
                if (Main::mainClass->saveBoxClass->geBoolValue("upgradeLevin5"))
                {
                    Main::mainClass->saveBoxClass->setValue("upgradeLevin5", false);
                    Main::mainClass->saveBoxClass->setValue(stars + this->costLevinUpgrade5);
                }
                this->upgradeUpdate();
            }
        }
        else if (this->container->cont->btnReset->currentFrame == 3)
        {
            this->container->cont->btnReset->gotoAndStop(1);
        }
        if (targetName == "acceptCase")
        {
            if (this->container->cont->btnAccept->currentFrame == 3)
            {
                this->container->cont->btnAccept->gotoAndStop(2);
                this->close();
            }
        }
        else if (this->container->cont->btnAccept->currentFrame == 3)
        {
            this->container->cont->btnAccept->gotoAndStop(1);
        }
        return;
    }// end function

    void Upgrades::upgradeUpdate()
    {
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[3] > 0)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem1"))
            {
                this->container->cont->golemUpgrade1->gotoAndStop(3);
                this->container->cont->golemUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade1)
            {
                this->container->cont->golemUpgrade1->gotoAndStop(1);
                std::setText(this->container->cont->golemUpgrade1->starsTXT,this->costGolemUpgrade1);
                this->container->cont->golemUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade1->upgradeCase->setMouseEnabled(true);
            }
            else
            {
                this->container->cont->golemUpgrade1->gotoAndStop(4);
                std::setText(this->container->cont->golemUpgrade1->starsTXT,this->costGolemUpgrade1);
                this->container->cont->golemUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem2"))
            {
                this->container->cont->golemUpgrade2->gotoAndStop(3);
                this->container->cont->golemUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow1->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade2 && Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem1"))
            {
                this->container->cont->golemUpgrade2->gotoAndStop(1);
                std::setText(this->container->cont->golemUpgrade2->starsTXT,this->costGolemUpgrade2);
                this->container->cont->golemUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade2->upgradeCase->setMouseEnabled(true);
                this->container->cont->golemArrow1->setVisible(false);
            }
            else
            {
                this->container->cont->golemUpgrade2->gotoAndStop(4);
                std::setText(this->container->cont->golemUpgrade2->starsTXT,this->costGolemUpgrade2);
                this->container->cont->golemUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow1->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem3"))
            {
                this->container->cont->golemUpgrade3->gotoAndStop(3);
                this->container->cont->golemUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow2->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade3 && Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem2"))
            {
                this->container->cont->golemUpgrade3->gotoAndStop(1);
                std::setText(this->container->cont->golemUpgrade3->starsTXT,this->costGolemUpgrade3);
                this->container->cont->golemUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade3->upgradeCase->setMouseEnabled(true);
                this->container->cont->golemArrow2->setVisible(false);
            }
            else
            {
                this->container->cont->golemUpgrade3->gotoAndStop(4);
                std::setText(this->container->cont->golemUpgrade3->starsTXT,this->costGolemUpgrade3);
                this->container->cont->golemUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow2->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem4"))
            {
                this->container->cont->golemUpgrade4->gotoAndStop(3);
                this->container->cont->golemUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow3->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade4 && Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem3"))
            {
                this->container->cont->golemUpgrade4->gotoAndStop(1);
                std::setText(this->container->cont->golemUpgrade4->starsTXT,this->costGolemUpgrade4);
                this->container->cont->golemUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade4->upgradeCase->setMouseEnabled(true);
                this->container->cont->golemArrow3->setVisible(false);
            }
            else
            {
                this->container->cont->golemUpgrade4->gotoAndStop(4);
                std::setText(this->container->cont->golemUpgrade4->starsTXT,this->costGolemUpgrade4);
                this->container->cont->golemUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow3->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem5"))
            {
                this->container->cont->golemUpgrade5->gotoAndStop(3);
                this->container->cont->golemUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow4->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade5 && Main::mainClass->saveBoxClass->geBoolValue("upgradeGolem4"))
            {
                this->container->cont->golemUpgrade5->gotoAndStop(1);
                std::setText(this->container->cont->golemUpgrade5->starsTXT,this->costGolemUpgrade5);
                this->container->cont->golemUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade5->upgradeCase->setMouseEnabled(true);
                this->container->cont->golemArrow4->setVisible(false);
            }
            else
            {
                this->container->cont->golemUpgrade5->gotoAndStop(4);
                std::setText(this->container->cont->golemUpgrade5->starsTXT,this->costGolemUpgrade5);
                this->container->cont->golemUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->golemUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->golemArrow4->setVisible(false);
            }
        }
        else
        {
            this->container->cont->golemUpgrade1->gotoAndStop(5);
            std::setText(this->container->cont->golemUpgrade1->starsTXT,this->costGolemUpgrade1);
            this->container->cont->golemUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->golemUpgrade1->upgradeCase->setMouseEnabled(false);
            this->container->cont->golemUpgrade2->gotoAndStop(5);
            std::setText(this->container->cont->golemUpgrade2->starsTXT,this->costGolemUpgrade2);
            this->container->cont->golemUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->golemUpgrade2->upgradeCase->setMouseEnabled(false);
            this->container->cont->golemArrow1->setVisible(false);
            this->container->cont->golemUpgrade3->gotoAndStop(5);
            std::setText(this->container->cont->golemUpgrade3->starsTXT,this->costGolemUpgrade3);
            this->container->cont->golemUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->golemUpgrade3->upgradeCase->setMouseEnabled(false);
            this->container->cont->golemArrow2->setVisible(false);
            this->container->cont->golemUpgrade4->gotoAndStop(5);
            std::setText(this->container->cont->golemUpgrade4->starsTXT,this->costGolemUpgrade4);
            this->container->cont->golemUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->golemUpgrade4->upgradeCase->setMouseEnabled(false);
            this->container->cont->golemArrow3->setVisible(false);
            this->container->cont->golemUpgrade5->gotoAndStop(5);
            std::setText(this->container->cont->golemUpgrade5->starsTXT,this->costGolemUpgrade5);
            this->container->cont->golemUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->golemUpgrade5->upgradeCase->setMouseEnabled(false);
            this->container->cont->golemArrow4->setVisible(false);
        }
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[1] > 0 || Main::mainClass->saveBoxClass.gameSave.data.saveNo > 3)
        {
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman1"))
            {
                this->container->cont->icemanUpgrade1->gotoAndStop(3);
                this->container->cont->icemanUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade1)
            {
                this->container->cont->icemanUpgrade1->gotoAndStop(1);
                std::setText(this->container->cont->icemanUpgrade1->starsTXT,this->costIcemanUpgrade1);
                this->container->cont->icemanUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade1->upgradeCase->setMouseEnabled(true);
            }
            else
            {
                this->container->cont->icemanUpgrade1->gotoAndStop(4);
                std::setText(this->container->cont->icemanUpgrade1->starsTXT,this->costIcemanUpgrade1);
                this->container->cont->icemanUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman2"))
            {
                this->container->cont->icemanUpgrade2->gotoAndStop(3);
                this->container->cont->icemanUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow1->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade2 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman1"))
            {
                this->container->cont->icemanUpgrade2->gotoAndStop(1);
                std::setText(this->container->cont->icemanUpgrade2->starsTXT,this->costIcemanUpgrade2);
                this->container->cont->icemanUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade2->upgradeCase->setMouseEnabled(true);
                this->container->cont->icemanArrow1->setVisible(false);
            }
            else
            {
                this->container->cont->icemanUpgrade2->gotoAndStop(4);
                std::setText(this->container->cont->icemanUpgrade2->starsTXT,this->costIcemanUpgrade2);
                this->container->cont->icemanUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow1->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman3"))
            {
                this->container->cont->icemanUpgrade3->gotoAndStop(3);
                this->container->cont->icemanUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow2->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade3 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman2"))
            {
                this->container->cont->icemanUpgrade3->gotoAndStop(1);
                std::setText(this->container->cont->icemanUpgrade3->starsTXT,this->costIcemanUpgrade3);
                this->container->cont->icemanUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade3->upgradeCase->setMouseEnabled(true);
                this->container->cont->icemanArrow2->setVisible(false);
            }
            else
            {
                this->container->cont->icemanUpgrade3->gotoAndStop(4);
                std::setText(this->container->cont->icemanUpgrade3->starsTXT,this->costIcemanUpgrade3);
                this->container->cont->icemanUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow2->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman4"))
            {
                this->container->cont->icemanUpgrade4->gotoAndStop(3);
                this->container->cont->icemanUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow3->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade4 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman3"))
            {
                this->container->cont->icemanUpgrade4->gotoAndStop(1);
                std::setText(this->container->cont->icemanUpgrade4->starsTXT,this->costIcemanUpgrade4);
                this->container->cont->icemanUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade4->upgradeCase->setMouseEnabled(true);
                this->container->cont->icemanArrow3->setVisible(false);
            }
            else
            {
                this->container->cont->icemanUpgrade4->gotoAndStop(4);
                std::setText(this->container->cont->icemanUpgrade4->starsTXT,this->costIcemanUpgrade4);
                this->container->cont->icemanUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow3->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman5"))
            {
                this->container->cont->icemanUpgrade5->gotoAndStop(3);
                this->container->cont->icemanUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow4->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade5 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIceman4"))
            {
                this->container->cont->icemanUpgrade5->gotoAndStop(1);
                std::setText(this->container->cont->icemanUpgrade5->starsTXT,this->costIcemanUpgrade5);
                this->container->cont->icemanUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade5->upgradeCase->setMouseEnabled(true);
                this->container->cont->icemanArrow4->setVisible(false);
            }
            else
            {
                this->container->cont->icemanUpgrade5->gotoAndStop(4);
                std::setText(this->container->cont->icemanUpgrade5->starsTXT,this->costIcemanUpgrade5);
                this->container->cont->icemanUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->icemanUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->icemanArrow4->setVisible(false);
            }
        }
        else
        {
            this->container->cont->icemanUpgrade1->gotoAndStop(5);
            std::setText(this->container->cont->icemanUpgrade1->starsTXT,this->costIcemanUpgrade1);
            this->container->cont->icemanUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->icemanUpgrade1->upgradeCase->setMouseEnabled(false);
            this->container->cont->icemanUpgrade2->gotoAndStop(5);
            std::setText(this->container->cont->icemanUpgrade2->starsTXT,this->costIcemanUpgrade2);
            this->container->cont->icemanUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->icemanUpgrade2->upgradeCase->setMouseEnabled(false);
            this->container->cont->icemanArrow1->setVisible(false);
            this->container->cont->icemanUpgrade3->gotoAndStop(5);
            std::setText(this->container->cont->icemanUpgrade3->starsTXT,this->costIcemanUpgrade3);
            this->container->cont->icemanUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->icemanUpgrade3->upgradeCase->setMouseEnabled(false);
            this->container->cont->icemanArrow2->setVisible(false);
            this->container->cont->icemanUpgrade4->gotoAndStop(5);
            std::setText(this->container->cont->icemanUpgrade4->starsTXT,this->costIcemanUpgrade4);
            this->container->cont->icemanUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->icemanUpgrade4->upgradeCase->setMouseEnabled(false);
            this->container->cont->icemanArrow3->setVisible(false);
            this->container->cont->icemanUpgrade5->gotoAndStop(5);
            std::setText(this->container->cont->icemanUpgrade5->starsTXT,this->costIcemanUpgrade5);
            this->container->cont->icemanUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->icemanUpgrade5->upgradeCase->setMouseEnabled(false);
            this->container->cont->icemanArrow4->setVisible(false);
        }
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[2] > 0)
        {
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir1"))
            {
                this->container->cont->airUpgrade1->gotoAndStop(3);
                this->container->cont->airUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade1)
            {
                this->container->cont->airUpgrade1->gotoAndStop(1);
                std::setText(this->container->cont->airUpgrade1->starsTXT,this->costAirUpgrade1);
                this->container->cont->airUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade1->upgradeCase->setMouseEnabled(true);
            }
            else
            {
                this->container->cont->airUpgrade1->gotoAndStop(4);
                std::setText(this->container->cont->airUpgrade1->starsTXT,this->costAirUpgrade1);
                this->container->cont->airUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir2"))
            {
                this->container->cont->airUpgrade2->gotoAndStop(3);
                this->container->cont->airUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow1->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade2 && Main::mainClass->saveBoxClass->geBoolValue("upgradeAir1"))
            {
                this->container->cont->airUpgrade2->gotoAndStop(1);
                std::setText(this->container->cont->airUpgrade2->starsTXT,this->costAirUpgrade2);
                this->container->cont->airUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade2->upgradeCase->setMouseEnabled(true);
                this->container->cont->airArrow1->setVisible(false);
            }
            else
            {
                this->container->cont->airUpgrade2->gotoAndStop(4);
                std::setText(this->container->cont->airUpgrade2->starsTXT,this->costAirUpgrade2);
                this->container->cont->airUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow1->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir3"))
            {
                this->container->cont->airUpgrade3->gotoAndStop(3);
                this->container->cont->airUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow2->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade3 && Main::mainClass->saveBoxClass->geBoolValue("upgradeAir2"))
            {
                this->container->cont->airUpgrade3->gotoAndStop(1);
                std::setText(this->container->cont->airUpgrade3->starsTXT,this->costAirUpgrade3);
                this->container->cont->airUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade3->upgradeCase->setMouseEnabled(true);
                this->container->cont->airArrow2->setVisible(false);
            }
            else
            {
                this->container->cont->airUpgrade3->gotoAndStop(4);
                std::setText(this->container->cont->airUpgrade3->starsTXT,this->costAirUpgrade3);
                this->container->cont->airUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow2->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir4"))
            {
                this->container->cont->airUpgrade4->gotoAndStop(3);
                this->container->cont->airUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow3->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade4 && Main::mainClass->saveBoxClass->geBoolValue("upgradeAir3"))
            {
                this->container->cont->airUpgrade4->gotoAndStop(1);
                std::setText(this->container->cont->airUpgrade4->starsTXT,this->costAirUpgrade4);
                this->container->cont->airUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade4->upgradeCase->setMouseEnabled(true);
                this->container->cont->airArrow3->setVisible(false);
            }
            else
            {
                this->container->cont->airUpgrade4->gotoAndStop(4);
                std::setText(this->container->cont->airUpgrade4->starsTXT,this->costAirUpgrade4);
                this->container->cont->airUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow3->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeAir5"))
            {
                this->container->cont->airUpgrade5->gotoAndStop(3);
                this->container->cont->airUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow4->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade5 && Main::mainClass->saveBoxClass->geBoolValue("upgradeAir4"))
            {
                this->container->cont->airUpgrade5->gotoAndStop(1);
                std::setText(this->container->cont->airUpgrade5->starsTXT,this->costAirUpgrade5);
                this->container->cont->airUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade5->upgradeCase->setMouseEnabled(true);
                this->container->cont->airArrow4->setVisible(false);
            }
            else
            {
                this->container->cont->airUpgrade5->gotoAndStop(4);
                std::setText(this->container->cont->airUpgrade5->starsTXT,this->costAirUpgrade5);
                this->container->cont->airUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->airUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->airArrow4->setVisible(false);
            }
        }
        else
        {
            this->container->cont->airUpgrade1->gotoAndStop(5);
            std::setText(this->container->cont->airUpgrade1->starsTXT,this->costAirUpgrade1);
            this->container->cont->airUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->airUpgrade1->upgradeCase->setMouseEnabled(false);
            this->container->cont->airUpgrade2->gotoAndStop(5);
            std::setText(this->container->cont->airUpgrade2->starsTXT,this->costAirUpgrade2);
            this->container->cont->airUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->airUpgrade2->upgradeCase->setMouseEnabled(false);
            this->container->cont->airArrow1->setVisible(false);
            this->container->cont->airUpgrade3->gotoAndStop(5);
            std::setText(this->container->cont->airUpgrade3->starsTXT,this->costAirUpgrade3);
            this->container->cont->airUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->airUpgrade3->upgradeCase->setMouseEnabled(false);
            this->container->cont->airArrow2->setVisible(false);
            this->container->cont->airUpgrade4->gotoAndStop(5);
            std::setText(this->container->cont->airUpgrade4->starsTXT,this->costAirUpgrade4);
            this->container->cont->airUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->airUpgrade4->upgradeCase->setMouseEnabled(false);
            this->container->cont->airArrow3->setVisible(false);
            this->container->cont->airUpgrade5->gotoAndStop(5);
            std::setText(this->container->cont->airUpgrade5->starsTXT,this->costAirUpgrade5);
            this->container->cont->airUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->airUpgrade5->upgradeCase->setMouseEnabled(false);
            this->container->cont->airArrow4->setVisible(false);
        }
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[1] > 0 || Main::mainClass->saveBoxClass.gameSave.data.saveNo > 3)
        {
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire1"))
            {
                this->container->cont->fireUpgrade1->gotoAndStop(3);
                this->container->cont->fireUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade1)
            {
                this->container->cont->fireUpgrade1->gotoAndStop(1);
                std::setText(this->container->cont->fireUpgrade1->starsTXT,this->costFireUpgrade1);
                this->container->cont->fireUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade1->upgradeCase->setMouseEnabled(true);
            }
            else
            {
                this->container->cont->fireUpgrade1->gotoAndStop(4);
                std::setText(this->container->cont->fireUpgrade1->starsTXT,this->costFireUpgrade1);
                this->container->cont->fireUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire2"))
            {
                this->container->cont->fireUpgrade2->gotoAndStop(3);
                this->container->cont->fireUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow1->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade2 && Main::mainClass->saveBoxClass->geBoolValue("upgradeFire1"))
            {
                this->container->cont->fireUpgrade2->gotoAndStop(1);
                std::setText(this->container->cont->fireUpgrade2->starsTXT,this->costFireUpgrade2);
                this->container->cont->fireUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade2->upgradeCase->setMouseEnabled(true);
                this->container->cont->fireArrow1->setVisible(false);
            }
            else
            {
                this->container->cont->fireUpgrade2->gotoAndStop(4);
                std::setText(this->container->cont->fireUpgrade2->starsTXT,this->costFireUpgrade2);
                this->container->cont->fireUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow1->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire3"))
            {
                this->container->cont->fireUpgrade3->gotoAndStop(3);
                this->container->cont->fireUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow2->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade3 && Main::mainClass->saveBoxClass->geBoolValue("upgradeFire2"))
            {
                this->container->cont->fireUpgrade3->gotoAndStop(1);
                std::setText(this->container->cont->fireUpgrade3->starsTXT,this->costFireUpgrade3);
                this->container->cont->fireUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade3->upgradeCase->setMouseEnabled(true);
                this->container->cont->fireArrow2->setVisible(false);
            }
            else
            {
                this->container->cont->fireUpgrade3->gotoAndStop(4);
                std::setText(this->container->cont->fireUpgrade3->starsTXT,this->costFireUpgrade3);
                this->container->cont->fireUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow2->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire4"))
            {
                this->container->cont->fireUpgrade4->gotoAndStop(3);
                this->container->cont->fireUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow3->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade4 && Main::mainClass->saveBoxClass->geBoolValue("upgradeFire3"))
            {
                this->container->cont->fireUpgrade4->gotoAndStop(1);
                std::setText(this->container->cont->fireUpgrade4->starsTXT,this->costFireUpgrade4);
                this->container->cont->fireUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade4->upgradeCase->setMouseEnabled(true);
                this->container->cont->fireArrow3->setVisible(false);
            }
            else
            {
                this->container->cont->fireUpgrade4->gotoAndStop(4);
                std::setText(this->container->cont->fireUpgrade4->starsTXT,this->costFireUpgrade4);
                this->container->cont->fireUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow3->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeFire5"))
            {
                this->container->cont->fireUpgrade5->gotoAndStop(3);
                this->container->cont->fireUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow4->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade5 && Main::mainClass->saveBoxClass->geBoolValue("upgradeFire4"))
            {
                this->container->cont->fireUpgrade5->gotoAndStop(1);
                std::setText(this->container->cont->fireUpgrade5->starsTXT,this->costFireUpgrade5);
                this->container->cont->fireUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade5->upgradeCase->setMouseEnabled(true);
                this->container->cont->fireArrow4->setVisible(false);
            }
            else
            {
                this->container->cont->fireUpgrade5->gotoAndStop(4);
                std::setText(this->container->cont->fireUpgrade5->starsTXT,this->costFireUpgrade5);
                this->container->cont->fireUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->fireUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->fireArrow4->setVisible(false);
            }
        }
        else
        {
            this->container->cont->fireUpgrade1->gotoAndStop(5);
            std::setText(this->container->cont->fireUpgrade1->starsTXT,this->costFireUpgrade1);
            this->container->cont->fireUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->fireUpgrade1->upgradeCase->setMouseEnabled(false);
            this->container->cont->fireUpgrade2->gotoAndStop(5);
            std::setText(this->container->cont->fireUpgrade2->starsTXT,this->costFireUpgrade2);
            this->container->cont->fireUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->fireUpgrade2->upgradeCase->setMouseEnabled(false);
            this->container->cont->fireArrow1->setVisible(false);
            this->container->cont->fireUpgrade3->gotoAndStop(5);
            std::setText(this->container->cont->fireUpgrade3->starsTXT,this->costFireUpgrade3);
            this->container->cont->fireUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->fireUpgrade3->upgradeCase->setMouseEnabled(false);
            this->container->cont->fireArrow2->setVisible(false);
            this->container->cont->fireUpgrade4->gotoAndStop(5);
            std::setText(this->container->cont->fireUpgrade4->starsTXT,this->costFireUpgrade4);
            this->container->cont->fireUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->fireUpgrade4->upgradeCase->setMouseEnabled(false);
            this->container->cont->fireArrow3->setVisible(false);
            this->container->cont->fireUpgrade5->gotoAndStop(5);
            std::setText(this->container->cont->fireUpgrade5->starsTXT,this->costFireUpgrade5);
            this->container->cont->fireUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->fireUpgrade5->upgradeCase->setMouseEnabled(false);
            this->container->cont->fireArrow4->setVisible(false);
        }
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[1] > 0 || Main::mainClass->saveBoxClass.gameSave.data.saveNo > 3)
        {
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce1"))
            {
                this->container->cont->iceUpgrade1->gotoAndStop(3);
                this->container->cont->iceUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade1)
            {
                this->container->cont->iceUpgrade1->gotoAndStop(1);
                std::setText(this->container->cont->iceUpgrade1->starsTXT,this->costIceUpgrade1);
                this->container->cont->iceUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade1->upgradeCase->setMouseEnabled(true);
            }
            else
            {
                this->container->cont->iceUpgrade1->gotoAndStop(4);
                std::setText(this->container->cont->iceUpgrade1->starsTXT,this->costIceUpgrade1);
                this->container->cont->iceUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce2"))
            {
                this->container->cont->iceUpgrade2->gotoAndStop(3);
                this->container->cont->iceUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow1->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade2 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIce1"))
            {
                this->container->cont->iceUpgrade2->gotoAndStop(1);
                std::setText(this->container->cont->iceUpgrade2->starsTXT,this->costIceUpgrade2);
                this->container->cont->iceUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade2->upgradeCase->setMouseEnabled(true);
                this->container->cont->iceArrow1->setVisible(false);
            }
            else
            {
                this->container->cont->iceUpgrade2->gotoAndStop(4);
                std::setText(this->container->cont->iceUpgrade2->starsTXT,this->costIceUpgrade2);
                this->container->cont->iceUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow1->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce3"))
            {
                this->container->cont->iceUpgrade3->gotoAndStop(3);
                this->container->cont->iceUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow2->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade3 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIce2"))
            {
                this->container->cont->iceUpgrade3->gotoAndStop(1);
                std::setText(this->container->cont->iceUpgrade3->starsTXT,this->costIceUpgrade3);
                this->container->cont->iceUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade3->upgradeCase->setMouseEnabled(true);
                this->container->cont->iceArrow2->setVisible(false);
            }
            else
            {
                this->container->cont->iceUpgrade3->gotoAndStop(4);
                std::setText(this->container->cont->iceUpgrade3->starsTXT,this->costIceUpgrade3);
                this->container->cont->iceUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow2->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce4"))
            {
                this->container->cont->iceUpgrade4->gotoAndStop(3);
                this->container->cont->iceUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow3->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade4 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIce3"))
            {
                this->container->cont->iceUpgrade4->gotoAndStop(1);
                std::setText(this->container->cont->iceUpgrade4->starsTXT,this->costIceUpgrade4);
                this->container->cont->iceUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade4->upgradeCase->setMouseEnabled(true);
                this->container->cont->iceArrow3->setVisible(false);
            }
            else
            {
                this->container->cont->iceUpgrade4->gotoAndStop(4);
                std::setText(this->container->cont->iceUpgrade4->starsTXT,this->costIceUpgrade4);
                this->container->cont->iceUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow3->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->geBoolValue("upgradeIce5"))
            {
                this->container->cont->iceUpgrade5->gotoAndStop(3);
                this->container->cont->iceUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow4->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->geIntValue("stars") >= this->costIceUpgrade5 && Main::mainClass->saveBoxClass->geBoolValue("upgradeIce4"))
            {
                this->container->cont->iceUpgrade5->gotoAndStop(1);
                std::setText(this->container->cont->iceUpgrade5->starsTXT,this->costIceUpgrade5);
                this->container->cont->iceUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade5->upgradeCase->setMouseEnabled(true);
                this->container->cont->iceArrow4->setVisible(false);
            }
            else
            {
                this->container->cont->iceUpgrade5->gotoAndStop(4);
                std::setText(this->container->cont->iceUpgrade5->starsTXT,this->costIceUpgrade5);
                this->container->cont->iceUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->iceUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->iceArrow4->setVisible(false);
            }
        }
        else
        {
            this->container->cont->iceUpgrade1->gotoAndStop(5);
            std::setText(this->container->cont->iceUpgrade1->starsTXT,this->costIceUpgrade1);
            this->container->cont->iceUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->iceUpgrade1->upgradeCase->setMouseEnabled(false);
            this->container->cont->iceUpgrade2->gotoAndStop(5);
            std::setText(this->container->cont->iceUpgrade2->starsTXT,this->costIceUpgrade2);
            this->container->cont->iceUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->iceUpgrade2->upgradeCase->setMouseEnabled(false);
            this->container->cont->iceArrow1->setVisible(false);
            this->container->cont->iceUpgrade3->gotoAndStop(5);
            std::setText(this->container->cont->iceUpgrade3->starsTXT,this->costIceUpgrade3);
            this->container->cont->iceUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->iceUpgrade3->upgradeCase->setMouseEnabled(false);
            this->container->cont->iceArrow2->setVisible(false);
            this->container->cont->iceUpgrade4->gotoAndStop(5);
            std::setText(this->container->cont->iceUpgrade4->starsTXT,this->costIceUpgrade4);
            this->container->cont->iceUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->iceUpgrade4->upgradeCase->setMouseEnabled(false);
            this->container->cont->iceArrow3->setVisible(false);
            this->container->cont->iceUpgrade5->gotoAndStop(5);
            std::setText(this->container->cont->iceUpgrade5->starsTXT,this->costIceUpgrade5);
            this->container->cont->iceUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->iceUpgrade5->upgradeCase->setMouseEnabled(false);
            this->container->cont->iceArrow4->setVisible(false);
        }
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[2] > 0)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1"))
            {
                this->container->cont->stoneUpgrade1->gotoAndStop(3);
                this->container->cont->stoneUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade1)
            {
                this->container->cont->stoneUpgrade1->gotoAndStop(1);
                std::setText(this->container->cont->stoneUpgrade1->starsTXT,this->costStoneUpgrade1);
                this->container->cont->stoneUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade1->upgradeCase->setMouseEnabled(true);
            }
            else
            {
                this->container->cont->stoneUpgrade1->gotoAndStop(4);
                std::setText(this->container->cont->stoneUpgrade1->starsTXT,this->costStoneUpgrade1);
                this->container->cont->stoneUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone2"))
            {
                this->container->cont->stoneUpgrade2->gotoAndStop(3);
                this->container->cont->stoneUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow1->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1"))
            {
                this->container->cont->stoneUpgrade2->gotoAndStop(1);
                std::setText(this->container->cont->stoneUpgrade2->starsTXT,this->costStoneUpgrade2);
                this->container->cont->stoneUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade2->upgradeCase->setMouseEnabled(true);
                this->container->cont->stoneArrow1->setVisible(false);
            }
            else
            {
                this->container->cont->stoneUpgrade2->gotoAndStop(4);
                std::setText(this->container->cont->stoneUpgrade2->starsTXT,this->costStoneUpgrade2);
                this->container->cont->stoneUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow1->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone3"))
            {
                this->container->cont->stoneUpgrade3->gotoAndStop(3);
                this->container->cont->stoneUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow2->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone2"))
            {
                this->container->cont->stoneUpgrade3->gotoAndStop(1);
                std::setText(this->container->cont->stoneUpgrade3->starsTXT,this->costStoneUpgrade3);
                this->container->cont->stoneUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade3->upgradeCase->setMouseEnabled(true);
                this->container->cont->stoneArrow2->setVisible(false);
            }
            else
            {
                this->container->cont->stoneUpgrade3->gotoAndStop(4);
                std::setText(this->container->cont->stoneUpgrade3->starsTXT,this->costStoneUpgrade3);
                this->container->cont->stoneUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow2->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone4"))
            {
                this->container->cont->stoneUpgrade4->gotoAndStop(3);
                this->container->cont->stoneUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow3->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone3"))
            {
                this->container->cont->stoneUpgrade4->gotoAndStop(1);
                std::setText(this->container->cont->stoneUpgrade4->starsTXT,this->costStoneUpgrade4);
                this->container->cont->stoneUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade4->upgradeCase->setMouseEnabled(true);
                this->container->cont->stoneArrow3->setVisible(false);
            }
            else
            {
                this->container->cont->stoneUpgrade4->gotoAndStop(4);
                std::setText(this->container->cont->stoneUpgrade4->starsTXT,this->costStoneUpgrade4);
                this->container->cont->stoneUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow3->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone5"))
            {
                this->container->cont->stoneUpgrade5->gotoAndStop(3);
                this->container->cont->stoneUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow4->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone4"))
            {
                this->container->cont->stoneUpgrade5->gotoAndStop(1);
                std::setText(this->container->cont->stoneUpgrade5->starsTXT,this->costStoneUpgrade5);
                this->container->cont->stoneUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade5->upgradeCase->setMouseEnabled(true);
                this->container->cont->stoneArrow4->setVisible(false);
            }
            else
            {
                this->container->cont->stoneUpgrade5->gotoAndStop(4);
                std::setText(this->container->cont->stoneUpgrade5->starsTXT,this->costStoneUpgrade5);
                this->container->cont->stoneUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->stoneUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->stoneArrow4->setVisible(false);
            }
        }
        else
        {
            this->container->cont->stoneUpgrade1->gotoAndStop(5);
            std::setText(this->container->cont->stoneUpgrade1->starsTXT,this->costStoneUpgrade1);
            this->container->cont->stoneUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->stoneUpgrade1->upgradeCase->setMouseEnabled(false);
            this->container->cont->stoneUpgrade2->gotoAndStop(5);
            std::setText(this->container->cont->stoneUpgrade2->starsTXT,this->costStoneUpgrade2);
            this->container->cont->stoneUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->stoneUpgrade2->upgradeCase->setMouseEnabled(false);
            this->container->cont->stoneArrow1->setVisible(false);
            this->container->cont->stoneUpgrade3->gotoAndStop(5);
            std::setText(this->container->cont->stoneUpgrade3->starsTXT,this->costStoneUpgrade3);
            this->container->cont->stoneUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->stoneUpgrade3->upgradeCase->setMouseEnabled(false);
            this->container->cont->stoneArrow2->setVisible(false);
            this->container->cont->stoneUpgrade4->gotoAndStop(5);
            std::setText(this->container->cont->stoneUpgrade4->starsTXT,this->costStoneUpgrade4);
            this->container->cont->stoneUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->stoneUpgrade4->upgradeCase->setMouseEnabled(false);
            this->container->cont->stoneArrow3->setVisible(false);
            this->container->cont->stoneUpgrade5->gotoAndStop(5);
            std::setText(this->container->cont->stoneUpgrade5->starsTXT,this->costStoneUpgrade5);
            this->container->cont->stoneUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->stoneUpgrade5->upgradeCase->setMouseEnabled(false);
            this->container->cont->stoneArrow4->setVisible(false);
        }
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[3] > 0)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin1"))
            {
                this->container->cont->levinUpgrade1->gotoAndStop(3);
                this->container->cont->levinUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade1)
            {
                this->container->cont->levinUpgrade1->gotoAndStop(1);
                std::setText(this->container->cont->levinUpgrade1->starsTXT,this->costLevinUpgrade1);
                this->container->cont->levinUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade1->upgradeCase->setMouseEnabled(true);
            }
            else
            {
                this->container->cont->levinUpgrade1->gotoAndStop(4);
                std::setText(this->container->cont->levinUpgrade1->starsTXT,this->costLevinUpgrade1);
                this->container->cont->levinUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade1->upgradeCase->setMouseEnabled(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin2"))
            {
                this->container->cont->levinUpgrade2->gotoAndStop(3);
                this->container->cont->levinUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow1->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin1"))
            {
                this->container->cont->levinUpgrade2->gotoAndStop(1);
                std::setText(this->container->cont->levinUpgrade2->starsTXT,this->costLevinUpgrade2);
                this->container->cont->levinUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade2->upgradeCase->setMouseEnabled(true);
                this->container->cont->levinArrow1->setVisible(false);
            }
            else
            {
                this->container->cont->levinUpgrade2->gotoAndStop(4);
                std::setText(this->container->cont->levinUpgrade2->starsTXT,this->costLevinUpgrade2);
                this->container->cont->levinUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade2->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow1->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin3"))
            {
                this->container->cont->levinUpgrade3->gotoAndStop(3);
                this->container->cont->levinUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow2->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin2"))
            {
                this->container->cont->levinUpgrade3->gotoAndStop(1);
                std::setText(this->container->cont->levinUpgrade3->starsTXT,this->costLevinUpgrade3);
                this->container->cont->levinUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade3->upgradeCase->setMouseEnabled(true);
                this->container->cont->levinArrow2->setVisible(false);
            }
            else
            {
                this->container->cont->levinUpgrade3->gotoAndStop(4);
                std::setText(this->container->cont->levinUpgrade3->starsTXT,this->costLevinUpgrade3);
                this->container->cont->levinUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade3->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow2->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))
            {
                this->container->cont->levinUpgrade4->gotoAndStop(3);
                this->container->cont->levinUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow3->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin3"))
            {
                this->container->cont->levinUpgrade4->gotoAndStop(1);
                std::setText(this->container->cont->levinUpgrade4->starsTXT,this->costLevinUpgrade4);
                this->container->cont->levinUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade4->upgradeCase->setMouseEnabled(true);
                this->container->cont->levinArrow3->setVisible(false);
            }
            else
            {
                this->container->cont->levinUpgrade4->gotoAndStop(4);
                std::setText(this->container->cont->levinUpgrade4->starsTXT,this->costLevinUpgrade4);
                this->container->cont->levinUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade4->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow3->setVisible(false);
            }
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin5"))
            {
                this->container->cont->levinUpgrade5->gotoAndStop(3);
                this->container->cont->levinUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow4->setVisible(true);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))
            {
                this->container->cont->levinUpgrade5->gotoAndStop(1);
                std::setText(this->container->cont->levinUpgrade5->starsTXT,this->costLevinUpgrade5);
                this->container->cont->levinUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade5->upgradeCase->setMouseEnabled(true);
                this->container->cont->levinArrow4->setVisible(false);
            }
            else
            {
                this->container->cont->levinUpgrade5->gotoAndStop(4);
                std::setText(this->container->cont->levinUpgrade5->starsTXT,this->costLevinUpgrade5);
                this->container->cont->levinUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
                this->container->cont->levinUpgrade5->upgradeCase->setMouseEnabled(false);
                this->container->cont->levinArrow4->setVisible(false);
            }
        }
        else
        {
            this->container->cont->levinUpgrade1->gotoAndStop(5);
            std::setText(this->container->cont->levinUpgrade1->starsTXT,this->costLevinUpgrade1);
            this->container->cont->levinUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->levinUpgrade1->upgradeCase->setMouseEnabled(false);
            this->container->cont->levinUpgrade2->gotoAndStop(5);
            std::setText(this->container->cont->levinUpgrade2->starsTXT,this->costLevinUpgrade2);
            this->container->cont->levinUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->levinUpgrade2->upgradeCase->setMouseEnabled(false);
            this->container->cont->levinArrow1->setVisible(false);
            this->container->cont->levinUpgrade3->gotoAndStop(5);
            std::setText(this->container->cont->levinUpgrade3->starsTXT,this->costLevinUpgrade3);
            this->container->cont->levinUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->levinUpgrade3->upgradeCase->setMouseEnabled(false);
            this->container->cont->levinArrow2->setVisible(false);
            this->container->cont->levinUpgrade4->gotoAndStop(5);
            std::setText(this->container->cont->levinUpgrade4->starsTXT,this->costLevinUpgrade4);
            this->container->cont->levinUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->levinUpgrade4->upgradeCase->setMouseEnabled(false);
            this->container->cont->levinArrow3->setVisible(false);
            this->container->cont->levinUpgrade5->gotoAndStop(5);
            std::setText(this->container->cont->levinUpgrade5->starsTXT,this->costLevinUpgrade5);
            this->container->cont->levinUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
            this->container->cont->levinUpgrade5->upgradeCase->setMouseEnabled(false);
            this->container->cont->levinArrow4->setVisible(false);
        }
        if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeIce1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeAir1"))
        {
            if (this->container->cont->btnReset->currentFrame == 4)
            {
                this->container->cont->btnReset->gotoAndStop(1);
                this->container->cont->btnReset->resetCase->setMouseEnabled(true);
            }
        }
        else if (this->container->cont->btnReset->currentFrame != 4)
        {
            this->container->cont->btnReset->gotoAndStop(4);
            this->container->cont->btnReset->resetCase->setMouseEnabled(false);
        }
        std::setText(this->container->cont->starsTXT,Main::mainClass->saveBoxClass->getIntValue("stars"));
        this->container->cont->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
        std::setText(Main::mainClass->levelsMenuClass->container->freeStars->cont->starsTXT,Main::mainClass->saveBoxClass->getIntValue("stars"));
        Main::mainClass->levelsMenuClass->container->freeStars->cont->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
        return;
    }// end function

    void Upgrades::manageListeners(string param1)
    {
		if (param1 == "on")
		{
			if (useNodeEvent)
				std::globalNode = this;
			this->enableMouseHandler(true);
			this->enableFrameHandler(true);
		}
		else if (param1 == "off")
		{
			this->disableMouseHandler();
			this->disableFrameHandler();
		}
    }// end function

    void Upgrades::close()
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true; 
            this->container->cont->setMouseChildren(false);
            this->container->cont->setMouseEnabled(false);
            Main::mainClass->levelsMenuClass->container->upgrades->gotoAndStop(1);
            //this->stage.frameRate = 60;
            if (Main::mainClass->saveBoxClass->getIntValue("stars") == 0)
            {
                Main::mainClass->levelsMenuClass->container->freeStars->setVisible(false);
            }
            else
            {
                Main::mainClass->levelsMenuClass->container->freeStars->gotoAndStop(1);
                Main::mainClass->levelsMenuClass->container->freeStars->cont->gotoAndStop(1);
                Main::mainClass->levelsMenuClass->container->freeStars->setVisible(true);
            }
        }
        return;
    }// end function

    void Upgrades::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
            this->levelsMenu->removeChild(this->levelsMenu->upgradesClass);
            this->levelsMenu->upgradesClass = NULL;
            this->levelsMenu->manageListeners("on");
        }
        return;
    }// end function

    //void Upgrades::reInit(event:Event)
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    this->stage.frameRate = 30;
    //    Main::mainClass->saveBoxClass.updateSever();
    //    return;
    //}// end function

} 

