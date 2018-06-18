#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_34::Unit_34():phase(0),teleportStatus(0),eyesFlag(false),eyesCounter(0),eyesCounter1(0),eyesCounter2(0),phaseRoad1(0),phaseRoad2(0),giveArmorFlag(false),takeAwayCastsFlag(false),speakFlag(false),notAtRoad(0),musicVolumeManageCounter(0),greenFlag(0),callUnitsCounter(0),roadFlag(false)
 		{
            this->readXML = &Main::mainClass->readXMLClass;
			return;
		}// end function 

        bool Unit_34::init()
        {
            typeUnit = 34;
            container = new Unit_mc(this, "unit34", typeUnit);  
			container->setScale(0.85);
			container->init();
			Unit::init();
			this->autorelease();  
			
			container->walkIn->stop();
            container->walkOut->stop();
            container->speak->stop();
             
            container->walkIn->setVisible(false);
            container->walkOut->setVisible(false);
            container->speak->setVisible(false);
 
            world->boss = this;
            readyDamage = false;
            moveFlag = false;
            mainMoveFlag = false;
            this->setVisible(false);
            if (std::random() < 0.5)
            {
                road = 1;
            }
            else
            {
                road = 2;
            }
            way = 3;
            if (road == 1)
            {
                path = this->readXML->bossArrayPhasePath[0][this->phaseRoad1];
            }
            else if (road == 2)
            {
                path = this->readXML->bossArrayPhasePath[1][this->phaseRoad2];
            }
            this->setPosition(398,158);
            //this->x = 398;
            //this->y = 158;
            this_pt =this->getPosition();// new Point(this->x, this->y);
            shoot_pt = container->localToGlobal(this_pt);//new Point(container->cont->x, container->cont->y));
            this->speakFlag = true;
            if (world->worldInterface->fasterFlag == 2)
            {
                world->worldInterface->fasterManage(false);
            }
            world->worldInterface->container->快.fastCase.setMouseEnabled(false);
            //Sounds.instance.playSound("snd_boss_start");
            return true;
        }// end function

        void Unit_34::animationHandler()
        {
            if (!dead && this->visible && !icemanFlag)
            {
                if (!airFlag && this->teleportStatus == 0 && !this->eyesFlag && !this->giveArmorFlag && !this->takeAwayCastsFlag && !this->speakFlag)
                {
                    if (this->readXML->bossArrayOfView.size() > 0)
                    {
                        if (this->readXML->bossArrayOfView[0][0] > 0)
                        {
                            this->readXML->bossArrayOfView[0][0] --;
                        }
                        else
                        {
                            this->changeRoad = this->readXML->bossArrayOfView[0][1];
                            this->readXML->bossArrayOfView.splice(0, 1);
                            this->phase++;
                            this->teleportStatus = 1;
                            readyDamage = false;
                            if (armorFlag)
                            {
                                stopAllEffects("armor");
                            }
                        }
                    }
                    if (this->readXML->bossArrayOfEnemies.size() > 0)
                    {
                        if (this->readXML->bossArrayOfEnemies[0].size() > 0)
                        {
                            if (this->readXML->bossArrayOfEnemies[0][0] > 0)
                            {
                                if (world->frameCounter == 30 && this->phase > 0)
                                {
                                    this->greenFlag = false;
                                    i = 0;
                                    while (i < world->listOfUnits.size())
                                    {
                                        if (world->listOfUnits[i]->myParent == this)
                                        {
                                            this->greenFlag = true;
                                            break;
                                        }
                                        i++;
                                    }
                                    if (!this->greenFlag)
                                    {
                                        this->readXML->bossArrayOfEnemies[0][0] = 1;
                                    }
                                }
                                this->readXML->bossArrayOfEnemies[0][0]--;
                            }
                            else
                            {
                                this->callUnitsCounter++;
                                if (this->callUnitsCounter == 1)
                                {
                                    this->eyesFlag = true;
                                }
                                tempObject = [];
                                tempObject = tempObject.concat(this->readXML->bossArrayOfEnemies[0]);
                                this->arrayTurn.push(tempObject);
                                this->readXML->bossArrayOfEnemies.splice(0, 1);
                            }
                        }
                    }
                    if (this->readXML->bossArrayOfArmor.length > 0)
                    {
                        if (this->readXML->bossArrayOfArmor[0] > 0)
                        {
                            this->readXML->bossArrayOfArmor[0] --;
                        }
                        else
                        {
                            this->readXML->bossArrayOfArmor.splice(0, 1);
                            this->giveArmorFlag = true;
                            //Sounds.instance.playSound("snd_boss_eyes");
                        }
                    }
                    if (this->readXML->bossArrayOfCasts.length > 0)
                    {
                        if (this->readXML->bossArrayOfCasts[0] > 0)
                        {
                            this->readXML->bossArrayOfCasts[0] --;
                        }
                        else
                        {
                            this->readXML->bossArrayOfCasts.splice(0, 1);
                            this->takeAwayCastsFlag = true;
                            //Sounds.instance.playSound("snd_boss_eyes");
                        }
                    }
                }
                else if (this->teleportStatus > 0)
                {
                    if (icemanFlag)
                    {
                        if (icemanCounter != 0)
                        {
                            icemanCounter = 0;
                        }
                    }
                    else if (this->teleportStatus == 1)
                    {
                        if (!container->walkIn->setVisible())
                        {
                            container->walkIn->setVisible(true);
                            stopAllEffects();
                            if (health < healthMax)
                            {
                                container->healthBar->setVisible(true);
                            } 
                            this->setMouseChildren(false);
                            this->setMouseEnabled(false);
                            //Sounds.instance.playSound("snd_boss_appearDisappear");
                        }
                        else if (container->walkIn->currentFrame < container->walkIn->totalFrames)
                        {
                            container->walkIn.gotoAndStop((container->walkIn->currentFrame + 1));
                            if (container->cont->alpha > 0)
                            {
                                container->cont->alpha = container->cont->alpha - 0.2;
                            }
                        }
                        else
                        {
                            container->walkIn.gotoAndStop(1);
                            container->walkIn->setVisible(false);
                            container->cont->alpha = 0;
                            container->contMcs->gotoAndStop(1);
                            this->teleportStatus = 2;
                            direction = "none";
                            if ((!this->roadFlag || this->changeRoad == "true") && health > 0)
                            {
                                this->roadFlag = true;
                                cocos2d::Point tempObject;
                                if (road == 1)
                                {
                                    if (this->phaseRoad1 < this->readXML->bossArrayPhasePath[0].length)
                                    {
                                        (this->phaseRoad1 + 1);
                                    }
                                    road = 2;
                                    path = this->readXML->bossArrayPhasePath[1][this->phaseRoad2];
                                    tempObject = world->bezierClass->getPathPoint(path, road, way);
                                }
                                else
                                {
                                    if (this->phaseRoad2 < this->readXML->bossArrayPhasePath[1].length)
                                    {
                                        this->phaseRoad2 ++;
                                    }
                                    road = 1;
                                    path = this->readXML->bossArrayPhasePath[0][this->phaseRoad1];
                                    tempObject = world->bezierClass->getPathPoint(path, road, way);
                                } 
                                container->setScale(0.67);
                                //container->scaleX = 0.67;
                                this->setPosition(tempObject);//x = tempObject.x;
                                //this->y = tempObject.y;
                                this_pt =tempObject;// new Point(this->x, this->y);
                                shoot_pt = container->localToGlobal(container->cont->getPosition());// new Point(container->cont->x, container->cont->y));
                            }
                            else
                            {
                                this->roadFlag = false;
                                container->setScale(0.85);
                                this->setPosition(398,158);
                                //this->x = 398;
                                //this->y = 158;
                                this_pt =this->getPosition();// new Point(this->x, this->y);
                                shoot_pt = container->localToGlobal(container->cont->getPosition());// new Point(container->cont->x, container->cont->y));
                                notAtRoad++;
                                if (health > 0)
                                {
                                    if (this->notAtRoad % 2)
                                    {
                                        this->speakFlag = true;
                                    }
                                }
                                else
                                {
                                    this->kill();
                                    return;
                                }
                            }
                        }
                    }
                    else if (this->teleportStatus == 2)
                    {
                        if (!container->walkOut->setVisible())
                        {
                            container->walkOut->setVisible(true);
                            //Sounds.instance.playSound("snd_boss_appearDisappear");
                        }
                        else if (container->walkOut->currentFrame < container->walkOut->totalFrames)
                        {
                            container->walkOut.gotoAndStop((container->walkOut->currentFrame + 1));
                            if (container->cont->alpha < 1)
                            {
                                container->cont->alpha = container->cont->alpha + 0.2;
                            }
                        }
                        else
                        {
                            container->walkOut.gotoAndStop(1);
                            container->walkOut->setVisible(false);
                            container->cont->alpha = 1;
                            this->teleportStatus = 0;
                            if (this->roadFlag)
                            {
                                readyDamage = true;
                            } 
                            this->setMouseChildren(true);
                            this->setMouseEnabled(true);
                        }
                    }
                }
                else if (this->eyesFlag)
                {
                    if (container->contMcs->currentFrame < 18)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                        if (container->contMcs->currentFrame == 2)
                        {
                            //Sounds.instance.playSound("snd_boss_eyes");
                        }
                    }
                    else if (this->eyesCounter == 0)
                    {
                        this->eyesCounter ++;
                        container->contMcs->gotoAndStop(1);
                    }
                    else
                    {
                        this->eyesFlag = false;
                        this->eyesCounter = 0;
                        container->contMcs->gotoAndStop(1);
                    }
                }
                else if (this->giveArmorFlag)
                {
                    if (container->contMcs->currentFrame < 19)
                    {
                        container->contMcs->gotoAndStop(19);
                    }
                    else if (container->contMcs->currentFrame < 36)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else if (this->eyesCounter1 == 0)
                    {
                        this->eyesCounter1 ++;
                        container->contMcs->gotoAndStop(19);
                    }
                    else if (this->eyesCounter1 == 1)
                    {
                        this->giveArmorFlag = false;
                        this->eyesCounter1 = 0;
                        container->contMcs->gotoAndStop(1);
                        i = 0;
                        while (i < world->listOfUnits.size())
                        { 
                            if (world->listOfUnits[i]->atStaged && world->listOfUnits[i]->readyDamage && !world->listOfUnits[i]->armorFlag && world->listOfUnits[i] != this)
                            {
                                world->listOfUnits[i]->armorPower = 90;
                                world->listOfUnits[i]->armorCounter = 80;
                            }
                            i++;
                        }
                    }
                }
                else if (this->takeAwayCastsFlag)
                {
                    if (container->contMcs->currentFrame < 37)
                    {
                        container->contMcs->gotoAndStop(37);
                    }
                    else if (container->contMcs->currentFrame < 54)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else if (this->eyesCounter2 == 0)
                    {
                        this->eyesCounter2 ++;
                        container->contMcs->gotoAndStop(37);
                    }
                    else if (this->eyesCounter2 == 1)
                    {
                        this->takeAwayCastsFlag = false;
                        this->eyesCounter2 = 0;
                        MovieClip* tempObject = new MovieClip("unit/","AnimUpgrade_mc");// AnimUpgrade_mc();
                        tempObject->stop();
                        tempObject->x = world->worldInterface->container->butCastGolem.x + world->worldInterface->container->butCastGolem.castGolemCase.x;
                        tempObject->y = world->worldInterface->container->butCastGolem.y + world->worldInterface->container->butCastGolem.castGolemCase.y;
                        tempObject->setMouseChildren(false);
                        tempObject->setMouseEnabled(false);
                        world->worldInterface->addChild(tempObject);
                        world->worldInterface->listOfAnimation.push(tempObject);
                        tempObject = new MovieClip("unit/","AnimUpgrade_mc");//AnimUpgrade_mc();
                        tempObject->stop();
                        tempObject->x = world->worldInterface->container->butCastIceman.x + world->worldInterface->container->butCastIceman.castIcemanCase.x;
                        tempObject->y = world->worldInterface->container->butCastIceman.y + world->worldInterface->container->butCastIceman.castIcemanCase.y;
                        tempObject->setMouseChildren(false);
                        tempObject->setMouseEnabled(false);
                        world->worldInterface->addChild(tempObject);
                        world->worldInterface->listOfAnimation.push(tempObject);
                        tempObject = new MovieClip("unit/","AnimUpgrade_mc");//AnimUpgrade_mc();
                        tempObject->stop();
                        tempObject->x = world->worldInterface->container->butCastAir.x + world->worldInterface->container->butCastAir.castAirCase.x;
                        tempObject->y = world->worldInterface->container->butCastAir.y + world->worldInterface->container->butCastAir.castAirCase.y;
                        tempObject->setMouseChildren(false);
                        tempObject->setMouseEnabled(false);
                        world->worldInterface->addChild(tempObject);
                        world->worldInterface->listOfAnimation.push(tempObject);
                        if (world->cast)
                        {
                            world->cast.kill();
                        }
                        world->worldInterface->castGolemCounter = 1;
                        world->worldInterface->container->butCastGolem.gotoAndStop(4);
                        world->worldInterface->container->butCastGolem.castGolemCase.setMouseEnabled(false);
                        world->worldInterface->container->butCastGolem.cont.contMask.scaleY = 0;
                        world->worldInterface->castIcemanCounter = 1;
                        world->worldInterface->container->butCastIceman.gotoAndStop(4);
                        world->worldInterface->container->butCastIceman.castIcemanCase.setMouseEnabled(false);
                        world->worldInterface->container->butCastIceman.cont.contMask.scaleY = 0;
                        world->worldInterface->castAirCounter = 1;
                        world->worldInterface->container->butCastAir.gotoAndStop(4);
                        world->worldInterface->container->butCastAir.castAirCase.setMouseEnabled(false);
                        world->worldInterface->container->butCastAir.cont.contMask.scaleY = 0;
                        Sounds.instance.playSound("snd_boss_castReset");
                    }
                }
                else if (this->speakFlag)
                {
                    if (!container->speak->setVisible())
                    {
                        container->speak->setVisible(true);
                        //Sounds.instance.playSound("snd_boss_speak");
                    }
                    else if (container->speak->currentFrame < container->speak->totalFrames)
                    {
                        container->speak.gotoAndStop((container->speak->currentFrame + 1));
                    }
                    else if (!container->speak.flag)
                    {
                        container->speak.flag = true;
                        container->speak.gotoAndStop(1);
                        if (this->musicVolumeManageCounter == 0)
                        {
                            this->musicVolumeManageCounter = 1;
                        }
                    }
                    else
                    {
                        container->speak.flag = false;
                        this->speakFlag = false;
                        container->speak.gotoAndStop(1);
                        container->speak->setVisible(false);
                        if (!world->worldInterface->container->快.fastCase.mouseEnabled)
                        {
                            world->worldInterface->container->快.fastCase.setMouseEnabled(true);
                        }
                    }
                }
            }
            if (this->arrayTurn.length > 0)
            {
                if (this->arrayTurn[0][1].length > 0)
                {
                    if (!this->arrayTurn[0][2])
                    {
                        if (this->arrayTurn[0][1][0][1] > 0)
                        {
                            this->arrayTurn[0][2] = this->arrayTurn[0][1][0][2];
                            Unit * tempObject = world->addUnit(this->arrayTurn[0][1][0][0], this->arrayTurn[0][1][0][7], this->arrayTurn[0][1][0][3], this->arrayTurn[0][1][0][4], this->arrayTurn[0][1][0][5], this->arrayTurn[0][1][0][6]);
                            tempObject->myParent = this;
                            this->arrayTurn[0][1][0][1] --;
                        }
                        else
                        {
                            this->arrayTurn[0][1].splice(0, 1);
                        }
                    }
                    else if (this->arrayTurn[0][2] > 0)
                    {
                        this->arrayTurn[0][2] --;
                    }
                    else if (this->arrayTurn[0][1][0][1] > 0)
                    {
                        this->arrayTurn[0][2] = this->arrayTurn[0][1][0][2];
                        Unit * tempObject = world->addUnit(this->arrayTurn[0][1][0][0], this->arrayTurn[0][1][0][7], this->arrayTurn[0][1][0][3], this->arrayTurn[0][1][0][4], this->arrayTurn[0][1][0][5], this->arrayTurn[0][1][0][6]);
                        tempObject->myParent = this;
                        this->arrayTurn[0][1][0][1] --;
                    }
                    else
                    {
                        this->arrayTurn[0][1].splice(0, 1);
                    }
                }
                else
                {
                    this->arrayTurn.splice(0, 1);
                }
            }
            if (this->musicVolumeManageCounter == 1)
            {
                if (Sounds.instance.musicChanel)
                {
                    if (Sounds.instance.musicChanel.soundTransform.volume < world->startMusicVolume)
                    {
                        Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume + world->startMusicVolume * 0.035, 0);
                    }
                    else
                    {
                        world->startMusicVolume = 0;
                        this->musicVolumeManageCounter = 2;
                    }
                }
                else
                {
                    world->startMusicVolume = 0;
                    this->musicVolumeManageCounter = 2;
                }
            }
            if (this->musicVolumeManageCounter == 3)
            {
                if (Sounds.instance.musicChanel)
                {
                    if (world->startMusicVolume == 0)
                    {
                        world->startMusicVolume = Sounds.instance.musicChanel.soundTransform.volume;
                    }
                    if (Sounds.instance.musicChanel.soundTransform.volume > world->startMusicVolume * 0.35)
                    {
                        Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume - world->startMusicVolume * 0.035, 0);
                    }
                    else
                    {
                        this->musicVolumeManageCounter = 4;
                    }
                }
                else
                {
                    this->musicVolumeManageCounter = 4;
                }
            }
            Unit::animationHandler();
            return;
        }// end function

        void Unit_34::kill()
        {
            if (this->roadFlag)
            {
                if (icemanFlag)
                {
                    if (icemanCounter != 0)
                    {
                        icemanCounter = 0;
                    }
                }
                this->teleportStatus = 1;
                readyDamage = false;
                if (world->worldInterface->fasterFlag == 2)
                {
                    world->worldInterface->fasterManage(false);
                }
                world->worldInterface->container->快.fastCase.setMouseEnabled(false);
                this->musicVolumeManageCounter = 3;
                return;
            }
            if (!dead && health <= 0)
            {
                tempObject =new MovieClip(world,"unit/","Unit34Death_mc","Unit34Death_mc");// new Indexes(new Unit34Death_mc(), 3);
                tempObject->setPosition(shoot_pt.x,shoot_pt.y - 44.5);//.x = shoot_pt.x;
                //tempObject.y = shoot_pt.y - 44.5;
                //new InTimer("bossDeath");
                //new InTimer("bossSpeakInDeath");
                world->wavesClass->listOfWaves[0].clear();// = [];
                world->wavesClass->listOfWaves[1].clear();//  = [];
                world->wavesClass->listOfWaves[2].clear();//  = [];
                world->wavesClass->wavesHandler();
                i = world->listOfUnits.size() - 1;
                while (i >= 0)
                { 
                    if (world->listOfUnits[i] != this)
                    {
                        world->listOfUnits[i]->health = 0;
                        world->listOfUnits[i]->kill();
                    }
                    i--;
                }
                i = world->listOfUnits.length - 1;
                while (i >= 0)
                { 
                    if (world->listOfUnits[i] != this)
                    {
                        world->listOfUnits[i]->health = 0;
                        world->listOfUnits[i]->kill();
                    }
                    i--;
                }
            }
            Unit::kill();
            return;
        }// end function

    }
}
