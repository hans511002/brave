#include "BaseHeaders.h"

#include "ReadXML.h"
#include "MainClass.h"
#include "engine/Waves.h"
#include "engine/World.h"
#include "engine/level/Level.h"

namespace engine
{ 
    void ReadXML::loadXMLData()//base.xml
	{
        this->xmlData = new XMLConfigParser("xml/base.xml", "base");
        this->readXMLData();
    } 
	void ReadXML::readXMLData() 
	{
		if (this->xmlData->getString("bezier.@build") == "true")
		{
			this->bezierBuildXML = true;
		}
		else
		{
			this->bezierBuildXML = false;
		}
		this->bezierRoadXML = this->xmlData->getInt("bezier.@road");
		this->bezierWayXML = this->xmlData->getInt("bezier.@way");
		vector<tinyxml2::XMLElement *> enemies = this->xmlData->getChildList("enemies.enemy");
		int tempObject = enemies.size();
		this->i = 0;
		while ( i < tempObject)
		{
			//listOfEnemiesXML[this->i] = [];

			this->listOfEnemiesXML[this->i][0] = this->xmlData->getInt(enemies.at(this->i), "@typeEnemy");
			this->listOfEnemiesXML[this->i][1] = this->xmlData->getFloat(enemies.at(this->i), "@speedK");
			this->listOfEnemiesXML[this->i][2] = this->xmlData->getFloat(enemies.at(this->i), "@health");
			this->listOfEnemiesXML[this->i][3] = this->xmlData->getInt(enemies.at(this->i), "@gold");
			this->listOfEnemiesXML[this->i][4] = this->xmlData->getFloat(enemies.at(this->i), "@fireDamageK") / 100;
			this->listOfEnemiesXML[this->i][5] = this->xmlData->getFloat(enemies.at(this->i), "@iceDamageK") / 100;
			this->listOfEnemiesXML[this->i][6] = this->xmlData->getFloat(enemies.at(this->i), "@stoneDamageK") / 100;
			this->listOfEnemiesXML[this->i][7] = this->xmlData->getFloat(enemies.at(this->i), "@levinDamageK") / 100;
			this->listOfEnemiesXML[this->i][8] = this->xmlData->getInt(enemies.at(this->i), "@costOfLiving");
			this->listOfEnemiesXML[this->i][9] = this->xmlData->getFloat(enemies.at(this->i), "@airResist") / 100;
			this->listOfEnemiesXML[this->i][10] = this->xmlData->getFloat(enemies.at(this->i), "@icemanResist") / 100;
			this->listOfEnemiesXML[this->i][11] = this->xmlData->getInt(enemies.at(this->i), "@replacementCount");
			 
			if (this->i == 17 || this->i == 18)
			{
				this->listOfEnemiesXML[this->i][30] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@invisibleTimer") * Main::fps);
				this->listOfEnemiesXML[this->i][31] = std::round(this->xmlData->getFloat(enemies.at(this->i),"@visibleTimer") * Main::fps);
			}
			else if (this->i == 19 || this->i == 20)
			{
				this->listOfEnemiesXML[this->i][30] = this->xmlData->getFloat(enemies.at(this->i), "@countNewEnemy");
			}
			else if (this->i == 21)
			{
				this->listOfEnemiesXML[this->i][30] = this->xmlData->getFloat(enemies.at(this->i), "blockTowerRadius");
			}
			else if (this->i == 22)
			{
				this->listOfEnemiesXML[this->i][30] = this->xmlData->getFloat(enemies.at(this->i), "@repairHealthPerc") / 100;
			}
			else if (this->i == 23)
			{
				this->listOfEnemiesXML[this->i][30] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@speedRunPerc") / 100);
				this->listOfEnemiesXML[this->i][31] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@speedRunTimerIce1") * Main::fps);
				this->listOfEnemiesXML[this->i][32] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@speedRunTimerIce2") * Main::fps);
				this->listOfEnemiesXML[this->i][33] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@speedRunTimerIce3") * Main::fps);
				this->listOfEnemiesXML[this->i][34] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@speedRunTimerIce4") * Main::fps);
			}
			else if (this->i == 24)
			{
				this->listOfEnemiesXML[this->i][30] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@armorTimer") * Main::fps);
			}
			else if (this->i == 26)
			{
				this->listOfEnemiesXML[this->i][30] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@teleportTimer") * Main::fps);
				this->listOfEnemiesXML[this->i][31] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@teleportStealthTimer") * Main::fps);
				this->listOfEnemiesXML[this->i][32] = this->xmlData->getFloat(enemies.at(this->i), "@teleportDistance");
				this->listOfEnemiesXML[this->i][33] = this->xmlData->getFloat(enemies.at(this->i), "@teleportRadius");
				this->listOfEnemiesXML[this->i][34] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@unitsCount"));
			}
			else if (this->i == 27)
			{
				this->listOfEnemiesXML[this->i][30] = this->xmlData->getFloat(enemies.at(this->i), "@giveHealthRadius");
				this->listOfEnemiesXML[this->i][31] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@giveHealthInterval") * Main::fps);
				this->listOfEnemiesXML[this->i][32] = this->xmlData->getFloat(enemies.at(this->i), "@giveHealth") / 100;
			}
			else if (this->i == 28 || this->i == 29)
			{
				this->listOfEnemiesXML[this->i][30] = this->xmlData->getFloat(enemies.at(this->i), "@deadZone");
				this->listOfEnemiesXML[this->i][31] = this->xmlData->getFloat(enemies.at(this->i), "@beginZone");
				this->listOfEnemiesXML[this->i][32] = this->xmlData->getFloat(enemies.at(this->i), "@endZone");
				this->listOfEnemiesXML[this->i][33] = this->xmlData->getFloat(enemies.at(this->i), "@returnHealth") / 100;
				this->listOfEnemiesXML[this->i][34] = std::round(this->xmlData->getFloat(enemies.at(this->i), "@stealthTimer") * Main::fps);
			}
			else if (this->i == 33)
			{ 
				vector<tinyxml2::XMLElement *> road1Phases = this->xmlData->getChildList(enemies.at(this->i), "phasePath.road1.phase");
				this->tempObject1 = road1Phases.size();
				//this->xmlData->getFloat(enemies.at(this->i), "phasePath.road1.phase").length();
				this->n = 0;
				while (this->n < this->tempObject1)
				{
					this->bossArrayPhasePath[0][this->n] = this->xmlData->getInt(road1Phases.at(this->n), "@path");
					//int(this->xmlData.enemies.enemy[this->i].phasePath.road1.phase[this->n].@path);
					n++;
				}
				vector<tinyxml2::XMLElement *> road2Phases = this->xmlData->getChildList(enemies.at(this->i), "phasePath.road2.phase");
				this->tempObject1 = road2Phases.size(); //this->xmlData.enemies.enemy[this->i].phasePath.road2.phase.length();
				this->n = 0;
				while (this->n < this->tempObject1)
				{
					this->bossArrayPhasePath[1][this->n] = this->xmlData->getInt(road2Phases.at(this->n), "@path");
					//int(this->xmlData.enemies.enemy[this->i].phasePath.road2.phase[this->n].@path);
					n++;
				}
				vector<tinyxml2::XMLElement *> phaseViewViewTimer = this->xmlData->getChildList(enemies.at(this->i), "phaseView.viewTimer");
				this->tempObject1 = phaseViewViewTimer.size(); //this->xmlData.enemies.enemy[this->i].phaseView.viewTimer.length();
				this->n = 0;
				while (this->n < this->tempObject1)
				{
					this->bossArrayOfView[this->n][0] = std::round(this->xmlData->getFloat(phaseViewViewTimer.at(this->n), "@timer") * Main::fps);
					//std::round(Number(this->xmlData.enemies.enemy[this->i].phaseView.viewTimer[this->n].@timer) * Main::fps);
					this->bossArrayOfView[this->n][1] = this->xmlData->getBool(phaseViewViewTimer.at(this->n), "@changeRoad");//"true"/"false"
					n++;
				}
				vector<tinyxml2::XMLElement *> phaseCallUnitsCallUnits = this->xmlData->getChildList(enemies.at(this->i), "phaseCallUnits.callUnits");
				this->tempObject1 = phaseCallUnitsCallUnits.size();// this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits.length();
				this->n = 0;
				while (this->n < this->tempObject1)
				{
					//this->bossArrayOfEnemies[this->n] = [];
					this->bossArrayOfEnemies0[this->n] = std::round(this->xmlData->getFloat(phaseCallUnitsCallUnits.at(this->n), "@timer") * Main::fps);
					//this->bossArrayOfEnemies[this->n][1] = [];
					if (this->bossArrayOfEnemies1.size()>this->n){
						if (this->bossArrayOfEnemies1[this->n]){
							delete[]  bossArrayOfEnemies1[this->n] ;
							this->bossArrayOfEnemies1[this->n] = 0;
						}
					}
					vector<tinyxml2::XMLElement *> phaseCallUnitsCallUnitsEnemy = this->xmlData->getChildList(phaseCallUnitsCallUnits.at(this->n), "enemy");
					this->tempObject2 = phaseCallUnitsCallUnitsEnemy.size();//this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy.length();
					this->m = 0;
					this->bossArrayOfEnemies1[this->n] =new int[tempObject2*8];
					while (this->m < this->tempObject2)
					{
						//this->bossArrayOfEnemies[this->n][1][this->m] = [];
						this->bossArrayOfEnemies1[this->n][this->m *8+ 0] = this->xmlData->getInt(phaseCallUnitsCallUnitsEnemy.at(this->m), "@typeUnit");
						// int(this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy[this->m].@typeUnit);
						this->bossArrayOfEnemies1[this->n][this->m * 8 + 1] = this->xmlData->getInt(phaseCallUnitsCallUnitsEnemy.at(this->m), "@count");
						//int(this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy[this->m].@count);
						this->bossArrayOfEnemies1[this->n][this->m * 8 + 2] = std::round(this->xmlData->getFloat(phaseCallUnitsCallUnitsEnemy.at(this->m), "@interval") * Main::fps);
						this->bossArrayOfEnemies1[this->n][this->m * 8 + 3] = this->xmlData->getInt(phaseCallUnitsCallUnitsEnemy.at(this->m), "@way");
						//int(this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy[this->m].@way);
						this->bossArrayOfEnemies1[this->n][this->m * 8 + 4] = this->xmlData->getInt(phaseCallUnitsCallUnitsEnemy.at(this->m), "@path");
						//int(this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy[this->m].@path);
						this->bossArrayOfEnemies1[this->n][this->m * 8 + 5] = this->xmlData->getInt(phaseCallUnitsCallUnitsEnemy.at(this->m), "@replacement");
						//int(this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy[this->m].@replacement);
						this->bossArrayOfEnemies1[this->n][this->m * 8 + 6] = this->xmlData->getInt(phaseCallUnitsCallUnitsEnemy.at(this->m), "@gate");
						//int(this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy[this->m].@gate);
						this->bossArrayOfEnemies1[this->n][this->m * 8 + 7] = this->xmlData->getInt(phaseCallUnitsCallUnitsEnemy.at(this->m), "@road");
						//int(this->xmlData.enemies.enemy[this->i].phaseCallUnits.callUnits[this->n].enemy[this->m].@road);
						m++;
					}
					n++;
				}
				vector<tinyxml2::XMLElement *> phaseArmorGos = this->xmlData->getChildList(enemies.at(this->i), "phaseArmorGo.armorGo");
				this->tempObject1 = phaseArmorGos.size();//this->xmlData.enemies.enemy[this->i].phaseArmorGo.armorGo.length();
				this->n = 0;
				while (this->n < this->tempObject1)
				{
					this->bossArrayOfArmor[n]=std::round(this->xmlData->getFloat(phaseArmorGos.at(this->n), "@timer") * Main::fps);
					n++;
				}
				vector<tinyxml2::XMLElement *> phaseCastGos = this->xmlData->getChildList(enemies.at(this->i), "phaseCastGo.castGo");
				this->tempObject1 = phaseCastGos.size();//this->xmlData.enemies.enemy[this->i].phaseCastGo.castGo.length();
				this->n = 0;
				while (this->n < this->tempObject1)
				{

					this->bossArrayOfCasts[n]=std::round(this->xmlData->getFloat(phaseCastGos.at(this->n), "@timer") * Main::fps);
					//this->bossArrayOfCasts.push(std::round(Number(this->xmlData.enemies.enemy[this->i].phaseCastGo.castGo[this->n].@timer) * Main::fps));
					n++;
				}
			}
			i++;
		}
		//vector<tinyxml2::XMLElement *> packsUnits = this->xmlData->getChildList( "packs.unit");
		//this->tempObject =packsUnits.size();// this->xmlData.packs.unit.length();
		this->assasinVisTrueTimer1XML = std::round(this->xmlData->getFloat( "assasinUnit.assasinVisTrueSec.@assasinUnit1") * Main::fps);
		//std::round(Number(this->xmlData.assasinUnit.assasinVisTrueSec.@assasinUnit1) * Main::fps);
		this->assasinVisTrueTimer2XML = std::round(this->xmlData->getFloat( "assasinUnit.assasinVisTrueSec.@assasinUnit2") * Main::fps);
		//std::round(Number(this->xmlData.assasinUnit.assasinVisTrueSec.@assasinUnit2) * Main::fps);
		this->assasinVisFalseTimer1XML = std::round(this->xmlData->getFloat( "assasinUnit.assasinVisFalseSec.@assasinUnit1") * Main::fps);
		//std::round(Number(this->xmlData.assasinUnit.assasinVisFalseSec.@assasinUnit1) * Main::fps);
		this->assasinVisFalseTimer2XML = std::round(this->xmlData->getFloat( "assasinUnit.assasinVisFalseSec.@assasinUnit2") * Main::fps);
		//std::round(Number(this->xmlData.assasinUnit.assasinVisFalseSec.@assasinUnit2) * Main::fps);
		this->creationOfNewUnits1XML = this->xmlData->getFloat( "creationOfNewUnits.count.@creationOfNewUnits1");
		//int(this->xmlData.creationOfNewUnits.count.@creationOfNewUnits1);
		this->creationOfNewUnits2XML =this->xmlData->getFloat( "creationOfNewUnits.count.@creationOfNewUnits2");
		// int(this->xmlData.creationOfNewUnits.count.@creationOfNewUnits2);
		this->intervalTimerGolemXML = std::round(this->xmlData->getFloat( "cast.download.@golemInterval") * Main::fps);
		//std::round(Number(this->xmlData.cast.download.@golemInterval) * Main::fps);
		this->intervalTimerIcemanXML = std::round(this->xmlData->getFloat( "cast.download.@icemanInterval") * Main::fps);
		//std::round(Number(this->xmlData.cast.download.@icemanInterval) * Main::fps);
		this->intervalTimerAirXML = std::round(this->xmlData->getFloat( "cast.download.@airInterval") * Main::fps);
		//std::round(Number(this->xmlData.cast.download.@airInterval) * Main::fps);
		this->savingOfTimeCast = std::round(this->xmlData->getFloat( "cast.download.@savingOfTime") * Main::fps);
		//std::round(Number(this->xmlData.cast.download.@savingOfTime) * Main::fps);
		this->castGolemHealthXML = this->xmlData->getFloat( "cast.golem.@health");
		//Number(this->xmlData.cast.golem.@health);
		this->castGolemSpeedXML = this->xmlData->getFloat( "cast.golem.@speed");
		//Number(this->xmlData.cast.golem.@speed);
		this->castIcemanSpeedXML = this->xmlData->getFloat( "cast.iceman.@speed");
		// Number(this->xmlData.cast.iceman.@speed);
		this->castIcemanFreezTimerXML = this->xmlData->getFloat( "cast.iceman.@freezTimer");
		// std::round(Number(this->xmlData.cast.iceman.@freezTimer) * Main::fps);
		this->castIcemanLifeTimerXML = std::round(this->xmlData->getFloat( "cast.iceman.@lifeTimer") * Main::fps);
		//std::round(Number(this->xmlData.cast.iceman.@lifeTimer) * Main::fps);
		this->castIcemanDamageXML = this->xmlData->getFloat("cast.iceman.@damagePerSec");
		//Number(this->xmlData.cast.iceman.@damagePerSec);
		this->airPowerXML = this->xmlData->getFloat("cast.air.@power");
		//Number(this->xmlData.cast.air.@power);
		this->airRadiusXML = this->xmlData->getFloat("cast.air.@radius");
		//Number(this->xmlData.cast.air.@radius);
		this->airLifeSecXML = std::round(this->xmlData->getFloat("cast.air.@lifeTimer") * Main::fps);
		//std::round(Number(this->xmlData.cast.air.@lifeTimer) * Main::fps);
		this->airSpacingXML = this->xmlData->getFloat("cast.air.@spacing");
		//Number(this->xmlData.cast.air.@spacing);
		this->airWaitTimerXML = std::round(this->xmlData->getFloat("cast.air.@shockTimer") * Main::fps);
		//std::round(Number(this->xmlData.cast.air.@shockTimer) * Main::fps);
		this->costTowerXML = this->xmlData->getInt("cost.tower.@cost");//int(this->xmlData.cost.tower.@cost);
		this->costTowerPlusXML = this->xmlData->getInt("cost.tower.@costPlus");//int(this->xmlData.cost.tower.@costPlus);
		this->costSlot2XML = this->xmlData->getInt("cost.tower.@slot2");//int(this->xmlData.cost.towerSlots.@slot2);
		this->costSlot3XML = this->xmlData->getInt("cost.tower.@slot3");//int(this->xmlData.cost.towerSlots.@slot3);
		this->costSlot4XML = this->xmlData->getInt("cost.tower.@slot4");//int(this->xmlData.cost.towerSlots.@slot4);
		
		this->listOfFirePriceXML[0] = this->xmlData->getInt("cost.fire.@step1");//int(this->xmlData.cost.fire.@step1);
		this->listOfFirePriceXML[1] = this->xmlData->getInt("cost.fire.@step2");//int(this->xmlData.cost.fire.@step2);
		this->listOfFirePriceXML[2] = this->xmlData->getInt("cost.fire.@step3");//int(this->xmlData.cost.fire.@step3);
		this->listOfFirePriceXML[3] = this->xmlData->getInt("cost.fire.@step4");//int(this->xmlData.cost.fire.@step4);
		this->listOfFirePriceXML[4] = this->xmlData->getInt("cost.fire.@step5");//int(this->xmlData.cost.fire.@step5);
		this->listOfFirePriceXML[5] = this->xmlData->getInt("cost.fire.@step6");//int(this->xmlData.cost.fire.@step6);
		this->listOfFirePriceXML[6] = this->xmlData->getInt("cost.fire.@step7");//int(this->xmlData.cost.fire.@step7);
		this->listOfFirePriceXML[7] = this->xmlData->getInt("cost.fire.@step8");//int(this->xmlData.cost.fire.@step8);
		this->listOfFirePriceXML[8] = this->xmlData->getInt("cost.fire.@step9");//int(this->xmlData.cost.fire.@step9);
		this->listOfFirePriceXML[9] = this->xmlData->getInt("cost.fire.@step10");//int(this->xmlData.cost.fire.@step10);
		this->listOfFirePriceXML[10] = this->xmlData->getInt("cost.fire.@step11");//int(this->xmlData.cost.fire.@step11);
		this->listOfFirePriceXML[11] = this->xmlData->getInt("cost.fire.@step12");//int(this->xmlData.cost.fire.@step12);
		this->listOfFirePriceXML[12] = this->xmlData->getInt("cost.fire.@step13");//int(this->xmlData.cost.fire.@step13);
		this->listOfFirePriceXML[13] = this->xmlData->getInt("cost.fire.@step14");//int(this->xmlData.cost.fire.@step14);
		this->listOfFirePriceXML[14] = this->xmlData->getInt("cost.fire.@step15");//int(this->xmlData.cost.fire.@step15);
		this->listOfFirePriceXML[15] = this->xmlData->getInt("cost.fire.@step16");//int(this->xmlData.cost.fire.@step16);
		this->listOfFirePriceXML[16] = this->xmlData->getInt("cost.fire.@step17");//int(this->xmlData.cost.fire.@step17);
		this->listOfFirePriceXML[17] = this->xmlData->getInt("cost.fire.@step18");//int(this->xmlData.cost.fire.@step18);
		this->listOfFirePriceXML[18] = this->xmlData->getInt("cost.fire.@step19");//int(this->xmlData.cost.fire.@step19);
		this->listOfFirePriceXML[19] = this->xmlData->getInt("cost.fire.@step20");//int(this->xmlData.cost.fire.@step20);
		this->listOfFirePriceXML[20] = this->xmlData->getInt("cost.fire.@step21");//int(this->xmlData.cost.fire.@step21);
		this->listOfFirePriceXML[21] = this->xmlData->getInt("cost.fire.@step22");//int(this->xmlData.cost.fire.@step22);
		this->listOfFirePriceXML[22] = this->xmlData->getInt("cost.fire.@step23");//int(this->xmlData.cost.fire.@step23);
		this->listOfFirePriceXML[23] = this->xmlData->getInt("cost.fire.@step24");//int(this->xmlData.cost.fire.@step24);
		this->listOfFirePriceXML[24] = this->xmlData->getInt("cost.fire.@step25");//int(this->xmlData.cost.fire.@step25);
		this->listOfFirePriceXML[25] = this->xmlData->getInt("cost.fire.@step26");//int(this->xmlData.cost.fire.@step26);
		this->listOfFirePriceXML[26] = this->xmlData->getInt("cost.fire.@step27");//int(this->xmlData.cost.fire.@step27);
		this->listOfFirePriceXML[27] = this->xmlData->getInt("cost.fire.@step28");//int(this->xmlData.cost.fire.@step28);
		this->listOfFirePriceXML[28] = this->xmlData->getInt("cost.fire.@step29");//int(this->xmlData.cost.fire.@step29);
		this->listOfFirePriceXML[29] = this->xmlData->getInt("cost.fire.@step30");//int(this->xmlData.cost.fire.@step30);
		this->listOfFirePriceXML[30] = this->xmlData->getInt("cost.fire.@step31");//int(this->xmlData.cost.fire.@step31);
		this->listOfFirePriceXML[31] = this->xmlData->getInt("cost.fire.@step32");//int(this->xmlData.cost.fire.@step32);
		this->listOfFirePriceXML[32] = this->xmlData->getInt("cost.fire.@step33");//int(this->xmlData.cost.fire.@step33);
		this->listOfFirePriceXML[33] = this->xmlData->getInt("cost.fire.@step34");//int(this->xmlData.cost.fire.@step34);
		this->listOfFirePriceXML[34] = this->xmlData->getInt("cost.fire.@step35");//int(this->xmlData.cost.fire.@step35);
		this->listOfFirePriceXML[35] = this->xmlData->getInt("cost.fire.@step36");//int(this->xmlData.cost.fire.@step36);
		this->listOfFirePriceXML[36] = this->xmlData->getInt("cost.fire.@step37");//int(this->xmlData.cost.fire.@step37);
		this->listOfFirePriceXML[37] = this->xmlData->getInt("cost.fire.@step38");//int(this->xmlData.cost.fire.@step38);
		this->listOfFirePriceXML[38] = this->xmlData->getInt("cost.fire.@step39");//int(this->xmlData.cost.fire.@step39);
		this->listOfFirePriceXML[39] = this->xmlData->getInt("cost.fire.@step40");//int(this->xmlData.cost.fire.@step40);
		this->listOfFirePriceXML[40] = this->xmlData->getInt("cost.fire.@step41");//int(this->xmlData.cost.fire.@step41);
		this->listOfIcePriceXML[0] = this->xmlData->getInt("cost.ice.@step1");//int(this->xmlData.cost.ice.@step1);
		this->listOfIcePriceXML[1] = this->xmlData->getInt("cost.ice.@step2");//int(this->xmlData.cost.ice.@step2);
		this->listOfIcePriceXML[2] = this->xmlData->getInt("cost.ice.@step3");//int(this->xmlData.cost.ice.@step3);
		this->listOfIcePriceXML[3] = this->xmlData->getInt("cost.ice.@step4");//int(this->xmlData.cost.ice.@step4);
		this->listOfIcePriceXML[4] = this->xmlData->getInt("cost.ice.@step5");//int(this->xmlData.cost.ice.@step5);
		this->listOfIcePriceXML[5] = this->xmlData->getInt("cost.ice.@step6");//int(this->xmlData.cost.ice.@step6);
		this->listOfIcePriceXML[6] = this->xmlData->getInt("cost.ice.@step7");//int(this->xmlData.cost.ice.@step7);
		this->listOfIcePriceXML[7] = this->xmlData->getInt("cost.ice.@step8");//int(this->xmlData.cost.ice.@step8);
		this->listOfIcePriceXML[8] = this->xmlData->getInt("cost.ice.@step9");//int(this->xmlData.cost.ice.@step9);
		this->listOfIcePriceXML[9] = this->xmlData->getInt("cost.ice.@step10");//int(this->xmlData.cost.ice.@step10);
		this->listOfIcePriceXML[10] = this->xmlData->getInt("cost.ice.@step11");//int(this->xmlData.cost.ice.@step11);
		this->listOfIcePriceXML[11] = this->xmlData->getInt("cost.ice.@step12");//int(this->xmlData.cost.ice.@step12);
		this->listOfIcePriceXML[12] = this->xmlData->getInt("cost.ice.@step13");//int(this->xmlData.cost.ice.@step13);
		this->listOfIcePriceXML[13] = this->xmlData->getInt("cost.ice.@step14");//int(this->xmlData.cost.ice.@step14);
		this->listOfIcePriceXML[14] = this->xmlData->getInt("cost.ice.@step15");//int(this->xmlData.cost.ice.@step15);
		this->listOfIcePriceXML[15] = this->xmlData->getInt("cost.ice.@step16");//int(this->xmlData.cost.ice.@step16);
		this->listOfIcePriceXML[16] = this->xmlData->getInt("cost.ice.@step17");//int(this->xmlData.cost.ice.@step17);
		this->listOfIcePriceXML[17] = this->xmlData->getInt("cost.ice.@step18");//int(this->xmlData.cost.ice.@step18);
		this->listOfIcePriceXML[18] = this->xmlData->getInt("cost.ice.@step19");//int(this->xmlData.cost.ice.@step19);
		this->listOfIcePriceXML[19] = this->xmlData->getInt("cost.ice.@step20");//int(this->xmlData.cost.ice.@step20);
		this->listOfIcePriceXML[20] = this->xmlData->getInt("cost.ice.@step21");//int(this->xmlData.cost.ice.@step21);
		this->listOfIcePriceXML[21] = this->xmlData->getInt("cost.ice.@step22");//int(this->xmlData.cost.ice.@step22);
		this->listOfIcePriceXML[22] = this->xmlData->getInt("cost.ice.@step23");//int(this->xmlData.cost.ice.@step23);
		this->listOfIcePriceXML[23] = this->xmlData->getInt("cost.ice.@step24");//int(this->xmlData.cost.ice.@step24);
		this->listOfIcePriceXML[24] = this->xmlData->getInt("cost.ice.@step25");//int(this->xmlData.cost.ice.@step25);
		this->listOfIcePriceXML[25] = this->xmlData->getInt("cost.ice.@step26");//int(this->xmlData.cost.ice.@step26);
		this->listOfIcePriceXML[26] = this->xmlData->getInt("cost.ice.@step27");//int(this->xmlData.cost.ice.@step27);
		this->listOfIcePriceXML[27] = this->xmlData->getInt("cost.ice.@step28");//int(this->xmlData.cost.ice.@step28);
		this->listOfIcePriceXML[28] = this->xmlData->getInt("cost.ice.@step29");//int(this->xmlData.cost.ice.@step29);
		this->listOfIcePriceXML[29] = this->xmlData->getInt("cost.ice.@step30");//int(this->xmlData.cost.ice.@step30);
		this->listOfIcePriceXML[30] = this->xmlData->getInt("cost.ice.@step31");//int(this->xmlData.cost.ice.@step31);
		this->listOfIcePriceXML[31] = this->xmlData->getInt("cost.ice.@step32");//int(this->xmlData.cost.ice.@step32);
		this->listOfIcePriceXML[32] = this->xmlData->getInt("cost.ice.@step33");//int(this->xmlData.cost.ice.@step33);
		this->listOfIcePriceXML[33] = this->xmlData->getInt("cost.ice.@step34");//int(this->xmlData.cost.ice.@step34);
		this->listOfIcePriceXML[34] = this->xmlData->getInt("cost.ice.@step35");//int(this->xmlData.cost.ice.@step35);
		this->listOfIcePriceXML[35] = this->xmlData->getInt("cost.ice.@step36");//int(this->xmlData.cost.ice.@step36);
		this->listOfIcePriceXML[36] = this->xmlData->getInt("cost.ice.@step37");//int(this->xmlData.cost.ice.@step37);
		this->listOfIcePriceXML[37] = this->xmlData->getInt("cost.ice.@step38");//int(this->xmlData.cost.ice.@step38);
		this->listOfIcePriceXML[38] = this->xmlData->getInt("cost.ice.@step39");//int(this->xmlData.cost.ice.@step39);
		this->listOfIcePriceXML[39] = this->xmlData->getInt("cost.ice.@step40");//int(this->xmlData.cost.ice.@step40);
		this->listOfStonePriceXML[0] = this->xmlData->getInt("cost.stone.@step1");//int(this->xmlData.cost.stone.@step1);
		this->listOfStonePriceXML[1] = this->xmlData->getInt("cost.stone.@step2");//int(this->xmlData.cost.stone.@step2);
		this->listOfStonePriceXML[2] = this->xmlData->getInt("cost.stone.@step3");//int(this->xmlData.cost.stone.@step3);
		this->listOfStonePriceXML[3] = this->xmlData->getInt("cost.stone.@step4");//int(this->xmlData.cost.stone.@step4);
		this->listOfStonePriceXML[4] = this->xmlData->getInt("cost.stone.@step5");//int(this->xmlData.cost.stone.@step5);
		this->listOfStonePriceXML[5] = this->xmlData->getInt("cost.stone.@step6");//int(this->xmlData.cost.stone.@step6);
		this->listOfStonePriceXML[6] = this->xmlData->getInt("cost.stone.@step7");//int(this->xmlData.cost.stone.@step7);
		this->listOfStonePriceXML[7] = this->xmlData->getInt("cost.stone.@step8");//int(this->xmlData.cost.stone.@step8);
		this->listOfStonePriceXML[8] = this->xmlData->getInt("cost.stone.@step9");//int(this->xmlData.cost.stone.@step9);
		this->listOfStonePriceXML[9] = this->xmlData->getInt("cost.stone.@step10");//int(this->xmlData.cost.stone.@step10);
		this->listOfStonePriceXML[10] = this->xmlData->getInt("cost.stone.@step11");//int(this->xmlData.cost.stone.@step11);
		this->listOfStonePriceXML[11] = this->xmlData->getInt("cost.stone.@step12");//int(this->xmlData.cost.stone.@step12);
		this->listOfStonePriceXML[12] = this->xmlData->getInt("cost.stone.@step13");//int(this->xmlData.cost.stone.@step13);
		this->listOfStonePriceXML[13] = this->xmlData->getInt("cost.stone.@step14");//int(this->xmlData.cost.stone.@step14);
		this->listOfStonePriceXML[14] = this->xmlData->getInt("cost.stone.@step15");//int(this->xmlData.cost.stone.@step15);
		this->listOfStonePriceXML[15] = this->xmlData->getInt("cost.stone.@step16");//int(this->xmlData.cost.stone.@step16);
		this->listOfStonePriceXML[16] = this->xmlData->getInt("cost.stone.@step17");//int(this->xmlData.cost.stone.@step17);
		this->listOfStonePriceXML[17] = this->xmlData->getInt("cost.stone.@step18");//int(this->xmlData.cost.stone.@step18);
		this->listOfStonePriceXML[18] = this->xmlData->getInt("cost.stone.@step19");//int(this->xmlData.cost.stone.@step19);
		this->listOfStonePriceXML[19] = this->xmlData->getInt("cost.stone.@step20");//int(this->xmlData.cost.stone.@step20);
		this->listOfStonePriceXML[20] = this->xmlData->getInt("cost.stone.@step21");//int(this->xmlData.cost.stone.@step21);
		this->listOfStonePriceXML[21] = this->xmlData->getInt("cost.stone.@step22");//int(this->xmlData.cost.stone.@step22);
		this->listOfStonePriceXML[22] = this->xmlData->getInt("cost.stone.@step23");//int(this->xmlData.cost.stone.@step23);
		this->listOfStonePriceXML[23] = this->xmlData->getInt("cost.stone.@step24");//int(this->xmlData.cost.stone.@step24);
		this->listOfStonePriceXML[24] = this->xmlData->getInt("cost.stone.@step25");//int(this->xmlData.cost.stone.@step25);
		this->listOfStonePriceXML[25] = this->xmlData->getInt("cost.stone.@step26");//int(this->xmlData.cost.stone.@step26);
		this->listOfStonePriceXML[26] = this->xmlData->getInt("cost.stone.@step27");//int(this->xmlData.cost.stone.@step27);
		this->listOfStonePriceXML[27] = this->xmlData->getInt("cost.stone.@step28");//int(this->xmlData.cost.stone.@step28);
		this->listOfStonePriceXML[28] = this->xmlData->getInt("cost.stone.@step29");//int(this->xmlData.cost.stone.@step29);
		this->listOfStonePriceXML[29] = this->xmlData->getInt("cost.stone.@step30");//int(this->xmlData.cost.stone.@step30);
		this->listOfStonePriceXML[30] = this->xmlData->getInt("cost.stone.@step31");//int(this->xmlData.cost.stone.@step31);
		this->listOfStonePriceXML[31] = this->xmlData->getInt("cost.stone.@step32");//int(this->xmlData.cost.stone.@step32);
		this->listOfStonePriceXML[32] = this->xmlData->getInt("cost.stone.@step33");//int(this->xmlData.cost.stone.@step33);
		this->listOfStonePriceXML[33] = this->xmlData->getInt("cost.stone.@step34");//int(this->xmlData.cost.stone.@step34);
		this->listOfStonePriceXML[34] = this->xmlData->getInt("cost.stone.@step35");//int(this->xmlData.cost.stone.@step35);
		this->listOfStonePriceXML[35] = this->xmlData->getInt("cost.stone.@step36");//int(this->xmlData.cost.stone.@step36);
		this->listOfStonePriceXML[36] = this->xmlData->getInt("cost.stone.@step37");//int(this->xmlData.cost.stone.@step37);
		this->listOfStonePriceXML[37] = this->xmlData->getInt("cost.stone.@step38");//int(this->xmlData.cost.stone.@step38);
		this->listOfStonePriceXML[38] = this->xmlData->getInt("cost.stone.@step39");//int(this->xmlData.cost.stone.@step39);
		this->listOfLevinPriceXML[0] = this->xmlData->getInt("cost.levin.@step1");//int(this->xmlData.cost.levin.@step1);
		this->listOfLevinPriceXML[1] = this->xmlData->getInt("cost.levin.@step2");//int(this->xmlData.cost.levin.@step2);
		this->listOfLevinPriceXML[2] = this->xmlData->getInt("cost.levin.@step3");//int(this->xmlData.cost.levin.@step3);
		this->listOfLevinPriceXML[3] = this->xmlData->getInt("cost.levin.@step4");//int(this->xmlData.cost.levin.@step4);
		this->listOfLevinPriceXML[4] = this->xmlData->getInt("cost.levin.@step5");//int(this->xmlData.cost.levin.@step5);
		this->listOfLevinPriceXML[5] = this->xmlData->getInt("cost.levin.@step6");//int(this->xmlData.cost.levin.@step6);
		this->listOfLevinPriceXML[6] = this->xmlData->getInt("cost.levin.@step7");//int(this->xmlData.cost.levin.@step7);
		this->listOfLevinPriceXML[7] = this->xmlData->getInt("cost.levin.@step8");//int(this->xmlData.cost.levin.@step8);
		this->listOfLevinPriceXML[8] = this->xmlData->getInt("cost.levin.@step9");//int(this->xmlData.cost.levin.@step9);
		this->listOfLevinPriceXML[9] = this->xmlData->getInt("cost.levin.@step10");//int(this->xmlData.cost.levin.@step10);
		this->listOfLevinPriceXML[10] = this->xmlData->getInt("cost.levin.@step11");//int(this->xmlData.cost.levin.@step11);
		this->listOfLevinPriceXML[11] = this->xmlData->getInt("cost.levin.@step12");//int(this->xmlData.cost.levin.@step12);
		this->listOfLevinPriceXML[12] = this->xmlData->getInt("cost.levin.@step13");//int(this->xmlData.cost.levin.@step13);
		this->listOfLevinPriceXML[13] = this->xmlData->getInt("cost.levin.@step14");//int(this->xmlData.cost.levin.@step14);
		this->listOfLevinPriceXML[14] = this->xmlData->getInt("cost.levin.@step15");//int(this->xmlData.cost.levin.@step15);
		this->listOfLevinPriceXML[15] = this->xmlData->getInt("cost.levin.@step16");//int(this->xmlData.cost.levin.@step16);
		this->listOfLevinPriceXML[16] = this->xmlData->getInt("cost.levin.@step17");//int(this->xmlData.cost.levin.@step17);
		this->listOfLevinPriceXML[17] = this->xmlData->getInt("cost.levin.@step18");//int(this->xmlData.cost.levin.@step18);
		this->listOfLevinPriceXML[18] = this->xmlData->getInt("cost.levin.@step19");//int(this->xmlData.cost.levin.@step19);
		this->listOfLevinPriceXML[19] = this->xmlData->getInt("cost.levin.@step20");//int(this->xmlData.cost.levin.@step20);
		this->listOfLevinPriceXML[20] = this->xmlData->getInt("cost.levin.@step21");//int(this->xmlData.cost.levin.@step21);
		this->listOfLevinPriceXML[21] = this->xmlData->getInt("cost.levin.@step22");//int(this->xmlData.cost.levin.@step22);
		this->listOfLevinPriceXML[22] = this->xmlData->getInt("cost.levin.@step23");//int(this->xmlData.cost.levin.@step23);
		this->listOfLevinPriceXML[23] = this->xmlData->getInt("cost.levin.@step24");//int(this->xmlData.cost.levin.@step24);
		this->listOfLevinPriceXML[24] = this->xmlData->getInt("cost.levin.@step25");//int(this->xmlData.cost.levin.@step25);
		this->listOfLevinPriceXML[25] = this->xmlData->getInt("cost.levin.@step26");//int(this->xmlData.cost.levin.@step26);
		this->listOfLevinPriceXML[26] = this->xmlData->getInt("cost.levin.@step27");//int(this->xmlData.cost.levin.@step27);
		this->listOfLevinPriceXML[27] = this->xmlData->getInt("cost.levin.@step28");//int(this->xmlData.cost.levin.@step28);
		this->listOfLevinPriceXML[28] = this->xmlData->getInt("cost.levin.@step29");//int(this->xmlData.cost.levin.@step29);
		this->listOfLevinPriceXML[29] = this->xmlData->getInt("cost.levin.@step30");//int(this->xmlData.cost.levin.@step30);
		this->listOfLevinPriceXML[30] = this->xmlData->getInt("cost.levin.@step31");//int(this->xmlData.cost.levin.@step31);
		this->listOfLevinPriceXML[31] = this->xmlData->getInt("cost.levin.@step32");//int(this->xmlData.cost.levin.@step32);
		this->listOfLevinPriceXML[32] = this->xmlData->getInt("cost.levin.@step33");//int(this->xmlData.cost.levin.@step33);
		this->listOfLevinPriceXML[33] = this->xmlData->getInt("cost.levin.@step34");//int(this->xmlData.cost.levin.@step34);
		this->listOfLevinPriceXML[34] = this->xmlData->getInt("cost.levin.@step35");//int(this->xmlData.cost.levin.@step35);
		this->listOfLevinPriceXML[35] = this->xmlData->getInt("cost.levin.@step36");//int(this->xmlData.cost.levin.@step36);
		this->listOfLevinPriceXML[36] = this->xmlData->getInt("cost.levin.@step37");//int(this->xmlData.cost.levin.@step37);
		this->listOfLevinPriceXML[37] = this->xmlData->getInt("cost.levin.@step38");//int(this->xmlData.cost.levin.@step38);
		this->costUltraFireStone = this->xmlData->getInt("cost.ultra.@fireStone");//int(this->xmlData.cost.ultra.@fireStone);
		this->costUltraIceLevin = this->xmlData->getInt("cost.ultra.@iceLevin");//int(this->xmlData.cost.ultra.@iceLevin);
		this->costUltraIceStone = this->xmlData->getInt("cost.ultra.@iceStone");//int(this->xmlData.cost.ultra.@iceStone);
		this->costUltraFireLevin = this->xmlData->getInt("cost.ultra.@fireLevin");//int(this->xmlData.cost.ultra.@fireLevin);
		this->costUltraAddFireStone = this->xmlData->getInt("cost.ultraAdditional.@fireStone");//int(this->xmlData.cost.ultraAdditional.@fireStone);
		this->costUltraAddIceLevin = this->xmlData->getInt("cost.ultraAdditional.@iceLevin");//int(this->xmlData.cost.ultraAdditional.@iceLevin);
		this->costUltraAddIceStone = this->xmlData->getInt("cost.ultraAdditional.@iceStone");//int(this->xmlData.cost.ultraAdditional.@iceStone);
		this->costUltraAddFireLevin = this->xmlData->getInt("cost.ultraAdditional.@fireLevin");//int(this->xmlData.cost.ultraAdditional.@fireLevin);
		this->fireEffectDamageXML = this->xmlData->getFloat("sphere.fireEffect.@damagePerc") / 100;//Number(this->xmlData.sphere.fireEffect.@damagePerc) / 100;
		this->iceEffectSlowdown1XML = this->xmlData->getFloat("sphere.iceEffect.@slowdown1Perc") / 100;//Number(this->xmlData.sphere.iceEffect.@slowdown1Perc) / 100;
		this->iceEffectSlowdown2XML = this->xmlData->getFloat("sphere.iceEffect.@slowdown2Perc") / 100;//Number(this->xmlData.sphere.iceEffect.@slowdown2Perc) / 100;
		this->iceEffectSlowdown3XML = this->xmlData->getFloat("sphere.iceEffect.@slowdown3Perc") / 100;//Number(this->xmlData.sphere.iceEffect.@slowdown3Perc) / 100;
		this->iceEffectSlowdown4XML = this->xmlData->getFloat("sphere.iceEffect.@slowdown4Perc") / 100;//Number(this->xmlData.sphere.iceEffect.@slowdown4Perc) / 100;
		this->iceEffectSlowdown1TimerXML = std::round(this->xmlData->getFloat("sphere.iceEffect.@slowdown1Timer") * Main::fps);//Number(this->xmlData.sphere.iceEffect.@slowdown1Timer) * Main::fps);
		this->iceEffectSlowdown2TimerXML = std::round(this->xmlData->getFloat("sphere.iceEffect.@slowdown2Timer") * Main::fps);//Number(this->xmlData.sphere.iceEffect.@slowdown2Timer) * Main::fps);
		this->iceEffectSlowdown3TimerXML = std::round(this->xmlData->getFloat("sphere.iceEffect.@slowdown3Timer") * Main::fps);//Number(this->xmlData.sphere.iceEffect.@slowdown3Timer) * Main::fps);
		this->iceEffectSlowdown4TimerXML = std::round(this->xmlData->getFloat("sphere.iceEffect.@slowdown4Timer") * Main::fps);//Number(this->xmlData.sphere.iceEffect.@slowdown4Timer) * Main::fps);
		this->stoneEffectRadiusXML = this->xmlData->getFloat("sphere.stoneEffect.@radius");//Number(this->xmlData.sphere.stoneEffect.@radius);
		this->levinEffectDamageXML = this->xmlData->getFloat("sphere.levinEffect.@damagePerc") / 100;//Number(this->xmlData.sphere.levinEffect.@damagePerc) / 100;
		this->levinEffectRadiusXML = this->xmlData->getFloat("sphere.levinEffect.@radius");//Number(this->xmlData.sphere.levinEffect.@radius);
		this->listOfMoveFireXML[0] = this->xmlData->getFloat("sphere.sphereOneMoveRadius.@fire");//Number(this->xmlData.sphere.sphereOneMoveRadius.@fire);
		this->listOfMoveIceXML[0] = this->xmlData->getFloat("sphere.sphereOneMoveRadius.@ice");//Number(this->xmlData.sphere.sphereOneMoveRadius.@ice);
		this->listOfMoveStoneXML[0] = this->xmlData->getFloat("sphere.sphereOneMoveRadius.@stone");//Number(this->xmlData.sphere.sphereOneMoveRadius.@stone);
		this->listOfMoveLevinXML[0] = this->xmlData->getFloat("sphere.sphereOneMoveRadius.@levin");//Number(this->xmlData.sphere.sphereOneMoveRadius.@levin);
		this->listOfMoveFireXML[1] = this->xmlData->getFloat("sphere.sphereOneMoveFireDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveFireDamage.@step1) * this->complexitySettingXML;
		this->listOfMoveFireXML[2] = this->xmlData->getFloat("sphere.sphereOneMoveFireDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveFireDamage.@step2) * this->complexitySettingXML;
		this->listOfMoveFireXML[3] = this->xmlData->getFloat("sphere.sphereOneMoveFireDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveFireDamage.@step3) * this->complexitySettingXML;
		this->listOfMoveFireXML[4] = this->xmlData->getFloat("sphere.sphereOneMoveFireDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveFireDamage.@step4) * this->complexitySettingXML;
		this->listOfMoveIceXML[1] = this->xmlData->getFloat("sphere.sphereOneMoveIceDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveIceDamage.@step1) * this->complexitySettingXML;
		this->listOfMoveIceXML[2] = this->xmlData->getFloat("sphere.sphereOneMoveIceDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveIceDamage.@step2) * this->complexitySettingXML;
		this->listOfMoveIceXML[3] = this->xmlData->getFloat("sphere.sphereOneMoveIceDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveIceDamage.@step3) * this->complexitySettingXML;
		this->listOfMoveIceXML[4] = this->xmlData->getFloat("sphere.sphereOneMoveIceDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveIceDamage.@step4) * this->complexitySettingXML;
		this->listOfMoveStoneXML[1] = this->xmlData->getFloat("sphere.sphereOneMoveStoneDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveStoneDamage.@step1) * this->complexitySettingXML;
		this->listOfMoveStoneXML[2] = this->xmlData->getFloat("sphere.sphereOneMoveStoneDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveStoneDamage.@step2) * this->complexitySettingXML;
		this->listOfMoveStoneXML[3] = this->xmlData->getFloat("sphere.sphereOneMoveStoneDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveStoneDamage.@step3) * this->complexitySettingXML;
		this->listOfMoveStoneXML[4] = this->xmlData->getFloat("sphere.sphereOneMoveStoneDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveStoneDamage.@step4) * this->complexitySettingXML;
		this->listOfMoveLevinXML[1] = this->xmlData->getFloat("sphere.sphereOneMoveLevinDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveLevinDamage.@step1) * this->complexitySettingXML;
		this->listOfMoveLevinXML[2] = this->xmlData->getFloat("sphere.sphereOneMoveLevinDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveLevinDamage.@step2) * this->complexitySettingXML;
		this->listOfMoveLevinXML[3] = this->xmlData->getFloat("sphere.sphereOneMoveLevinDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveLevinDamage.@step3) * this->complexitySettingXML;
		this->listOfMoveLevinXML[4] = this->xmlData->getFloat("sphere.sphereOneMoveLevinDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.sphere.sphereOneMoveLevinDamage.@step4) * this->complexitySettingXML;
		this->getAllLiveTimer = std::round(this->xmlData->getFloat("sphere.getAll.@liveTimer") * Main::fps);//Number(this->xmlData.sphere.getAll.@liveTimer) * Main::fps);
		this->getAllDamagePerSec = this->xmlData->getFloat("sphere.getAll.@damagePerSecond") / 30 * this->complexitySettingXML;//Number(this->xmlData.sphere.getAll.@damagePerSecond) / 30 * this->complexitySettingXML;
		this->getAllLittleMultiply = this->xmlData->getFloat("sphere.getAll.@getAllLittleMultiply") / 100;//Number(this->xmlData.sphere.getAll.@getAllLittleMultiply) / 100);
		this->getAllLittleDoubleMultiply = this->xmlData->getFloat("sphere.getAll.@getAllLittleDoubleMultiply") / 100;//Number(this->xmlData.sphere.getAll.@getAllLittleDoubleMultiply) / 100);
		this->getAllMultiply = this->xmlData->getFloat("sphere.getAll.@getAllMultiplyX1");//Number(this->xmlData.sphere.getAll.@getAllMultiplyX1);
		this->getAllMultiply1 = this->xmlData->getFloat("sphere.getAll.@getAllMultiplyX2");//Number(this->xmlData.sphere.getAll.@getAllMultiplyX2);
		this->getAllMultiply2 = this->xmlData->getFloat("sphere.getAll.@getAllMultiplyX3");//Number(this->xmlData.sphere.getAll.@getAllMultiplyX3);
		this->listOfSpheresRadius[0] = this->xmlData->getFloat("towers.radius.@tower1");//Number(this->xmlData.towers.radius.@tower1);
		this->listOfSpheresRadius[1] = this->xmlData->getFloat("towers.radius.@tower2");//Number(this->xmlData.towers.radius.@tower2);
		this->listOfSpheresRadius[2] = this->xmlData->getFloat("towers.radius.@tower3");//Number(this->xmlData.towers.radius.@tower3);
		this->listOfSpheresRadius[3] = this->xmlData->getFloat("towers.radius.@tower4");//Number(this->xmlData.towers.radius.@tower4);
		this->listOfFireTowerDamageXML[0] = this->xmlData->getFloat("towers.fireDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.towers.fireDamage.@step1) * this->complexitySettingXML;
		this->listOfFireTowerDamageXML[1] = this->xmlData->getFloat("towers.fireDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.towers.fireDamage.@step2) * this->complexitySettingXML;
		this->listOfFireTowerDamageXML[2] = this->xmlData->getFloat("towers.fireDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.towers.fireDamage.@step3) * this->complexitySettingXML;
		this->listOfFireTowerDamageXML[3] = this->xmlData->getFloat("towers.fireDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.towers.fireDamage.@step4) * this->complexitySettingXML;
		this->listOfIceTowerDamageXML[0] = this->xmlData->getFloat("towers.iceDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.towers.iceDamage.@step1) * this->complexitySettingXML;
		this->listOfIceTowerDamageXML[1] = this->xmlData->getFloat("towers.iceDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.towers.iceDamage.@step2) * this->complexitySettingXML;
		this->listOfIceTowerDamageXML[2] = this->xmlData->getFloat("towers.iceDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.towers.iceDamage.@step3) * this->complexitySettingXML;
		this->listOfIceTowerDamageXML[3] = this->xmlData->getFloat("towers.iceDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.towers.iceDamage.@step4) * this->complexitySettingXML;
		this->listOfStoneTowerDamageXML[0] = this->xmlData->getFloat("towers.stoneDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.towers.stoneDamage.@step1) * this->complexitySettingXML;
		this->listOfStoneTowerDamageXML[1] = this->xmlData->getFloat("towers.stoneDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.towers.stoneDamage.@step2) * this->complexitySettingXML;
		this->listOfStoneTowerDamageXML[2] = this->xmlData->getFloat("towers.stoneDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.towers.stoneDamage.@step3) * this->complexitySettingXML;
		this->listOfStoneTowerDamageXML[3] = this->xmlData->getFloat("towers.stoneDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.towers.stoneDamage.@step4) * this->complexitySettingXML;
		this->listOfLevinTowerDamageXML[0] = this->xmlData->getFloat("towers.levinDamage.@step1") * this->complexitySettingXML;//Number(this->xmlData.towers.levinDamage.@step1) * this->complexitySettingXML;
		this->listOfLevinTowerDamageXML[1] = this->xmlData->getFloat("towers.levinDamage.@step2") * this->complexitySettingXML;//Number(this->xmlData.towers.levinDamage.@step2) * this->complexitySettingXML;
		this->listOfLevinTowerDamageXML[2] = this->xmlData->getFloat("towers.levinDamage.@step3") * this->complexitySettingXML;//Number(this->xmlData.towers.levinDamage.@step3) * this->complexitySettingXML;
		this->listOfLevinTowerDamageXML[3] = this->xmlData->getFloat("towers.levinDamage.@step4") * this->complexitySettingXML;//Number(this->xmlData.towers.levinDamage.@step4) * this->complexitySettingXML;
		this->towerFireEffectDamageXML = this->xmlData->getFloat("towers.fireEffect.@damagePerc") / 100 * this->complexitySettingXML;//Number(this->xmlData.towers.fireEffect.@damagePerc) / 100 * this->complexitySettingXML;
		this->towerIceEffectSlowdownXML[0] = this->xmlData->getFloat("towers.iceEffect.@slowdown1Perc") / 100;//Number(this->xmlData.towers.iceEffect.@slowdown1Perc) / 100;
		this->towerIceEffectSlowdownXML[1] = this->xmlData->getFloat("towers.iceEffect.@slowdown2Perc") / 100;//Number(this->xmlData.towers.iceEffect.@slowdown2Perc) / 100;
		this->towerIceEffectSlowdownXML[2] = this->xmlData->getFloat("towers.iceEffect.@slowdown3Perc") / 100;//Number(this->xmlData.towers.iceEffect.@slowdown3Perc) / 100;
		this->towerIceEffectSlowdownXML[3] = this->xmlData->getFloat("towers.iceEffect.@slowdown4Perc") / 100;//Number(this->xmlData.towers.iceEffect.@slowdown4Perc) / 100;
		this->towerIceEffectSlowdownXML[4] = std::round(this->xmlData->getFloat("towers.iceEffect.@slowdown1Timer") * Main::fps);//Number(this->xmlData.towers.iceEffect.@slowdown1Timer) * Main::fps);
		this->towerIceEffectSlowdownXML[5] = std::round(this->xmlData->getFloat("towers.iceEffect.@slowdown2Timer") * Main::fps);//Number(this->xmlData.towers.iceEffect.@slowdown2Timer) * Main::fps);
		this->towerIceEffectSlowdownXML[6] = std::round(this->xmlData->getFloat("towers.iceEffect.@slowdown3Timer") * Main::fps);//Number(this->xmlData.towers.iceEffect.@slowdown3Timer) * Main::fps);
		this->towerIceEffectSlowdownXML[7] = std::round(this->xmlData->getFloat("towers.iceEffect.@slowdown4Timer") * Main::fps);//Number(this->xmlData.towers.iceEffect.@slowdown4Timer) * Main::fps);
		this->towerStoneEffectRadiusXML = this->xmlData->getFloat("towers.stoneEffect.@radius");//Number(this->xmlData.towers.stoneEffect.@radius);
		this->towerLevinEffectDamageXML = this->xmlData->getFloat("towers.levinEffect.@damagePerc") / 100 * this->complexitySettingXML;//Number(this->xmlData.towers.levinEffect.@damagePerc) / 100 * this->complexitySettingXML;
		this->towerLevinEffectRadiusXML = this->xmlData->getFloat("towers.levinEffect.@radius");//Number(this->xmlData.towers.levinEffect.@radius);
		this->fireTowerIntervalXML = std::round(this->xmlData->getFloat("towers.spheresInterval.@fire") * Main::fps);//Number(this->xmlData.towers.spheresInterval.@fire) * Main::fps);
		this->iceTowerIntervalXML = std::round(this->xmlData->getFloat("towers.spheresInterval.@ice") * Main::fps);//Number(this->xmlData.towers.spheresInterval.@ice) * Main::fps);
		this->stoneTowerIntervalXML = std::round(this->xmlData->getFloat("towers.spheresInterval.@stone") * Main::fps);//Number(this->xmlData.towers.spheresInterval.@stone) * Main::fps);
		this->levinTowerIntervalXML = std::round(this->xmlData->getFloat("towers.spheresInterval.@levin") * Main::fps);//Number(this->xmlData.towers.spheresInterval.@levin) * Main::fps);
		this->listOfFireProbability[0] = this->xmlData->getInt("towers.probability.fire.@step1");//int(this->xmlData.towers.probability.fire.@step1);
		this->listOfFireProbability[1] = this->xmlData->getInt("towers.probability.fire.@step2");//int(this->xmlData.towers.probability.fire.@step2);
		this->listOfFireProbability[2] = this->xmlData->getInt("towers.probability.fire.@step3");//int(this->xmlData.towers.probability.fire.@step3);
		this->listOfFireProbability[3] = this->xmlData->getInt("towers.probability.fire.@step4");//int(this->xmlData.towers.probability.fire.@step4);
		this->listOfIceProbability[0] = this->xmlData->getInt("towers.probability.ice.@step1");//int(this->xmlData.towers.probability.ice.@step1);
		this->listOfIceProbability[1] = this->xmlData->getInt("towers.probability.ice.@step2");//int(this->xmlData.towers.probability.ice.@step2);
		this->listOfIceProbability[2] = this->xmlData->getInt("towers.probability.ice.@step3");//int(this->xmlData.towers.probability.ice.@step3);
		this->listOfIceProbability[3] = this->xmlData->getInt("towers.probability.ice.@step4");//int(this->xmlData.towers.probability.ice.@step4);
		this->listOfLevinProbability[0] = this->xmlData->getInt("towers.probability.levin.@step1");//int(this->xmlData.towers.probability.levin.@step1);
		this->listOfLevinProbability[1] = this->xmlData->getInt("towers.probability.levin.@step2");//int(this->xmlData.towers.probability.levin.@step2);
		this->listOfLevinProbability[2] = this->xmlData->getInt("towers.probability.levin.@step3");//int(this->xmlData.towers.probability.levin.@step3);
		this->listOfLevinProbability[3] = this->xmlData->getInt("towers.probability.levin.@step4");//int(this->xmlData.towers.probability.levin.@step4);
		this->ultraFireStoneDamageXML = this->xmlData->getFloat("towers.ultraFireStone.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraFireStone.@damage) * this->complexitySettingXML;
		this->ultraFireStoneIntervalXML = std::round(this->xmlData->getFloat("towers.ultraFireStone.@interval") * Main::fps);//Number(this->xmlData.towers.ultraFireStone.@interval) * Main::fps);
		this->ultraFireStoneRadiusXML = this->xmlData->getFloat("towers.ultraFireStone.@radius");//Number(this->xmlData.towers.ultraFireStone.@radius);
		this->ultraFireStoneDamageRadiusXML = this->xmlData->getFloat("towers.ultraFireStone.@damageRadius");//Number(this->xmlData.towers.ultraFireStone.@damageRadius);
		this->ultraAddFireStoneDamageXML = this->xmlData->getFloat("towers.ultraAdditionalFireStone.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraAdditionalFireStone.@damage) * this->complexitySettingXML;
		this->ultraAddFireStoneIntervalXML = std::round(this->xmlData->getFloat("towers.ultraAdditionalFireStone.@interval") * Main::fps);//Number(this->xmlData.towers.ultraAdditionalFireStone.@interval) * Main::fps);
		this->ultraAddFireStoneRadiusXML = this->xmlData->getFloat("towers.ultraAdditionalFireStone.@radius");//Number(this->xmlData.towers.ultraAdditionalFireStone.@radius);
		this->ultraAddFireStoneSlowdownTimerXML = std::round(this->xmlData->getFloat("towers.ultraAdditionalFireStone.@slowdownInterval") * Main::fps);//Number(this->xmlData.towers.ultraAdditionalFireStone.@slowdownInterval) * Main::fps);
		this->ultraIceLevinDamageXML = this->xmlData->getFloat("towers.ultraIceLevin.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraIceLevin.@damage) * this->complexitySettingXML;
		this->ultraIceLevinIntervalXML = std::round(this->xmlData->getFloat("towers.ultraIceLevin.@interval") * Main::fps);//Number(this->xmlData.towers.ultraIceLevin.@interval) * Main::fps);
		this->ultraIceLevinRadiusXML = this->xmlData->getFloat("towers.ultraIceLevin.@radius");//Number(this->xmlData.towers.ultraIceLevin.@radius);
		this->ultraIceLevinSlowdownPowerXML = this->xmlData->getFloat("towers.ultraIceLevin.@slowdownPower") / 100;//Number(this->xmlData.towers.ultraIceLevin.@slowdownPower) / 100;
		this->ultraIceLevinSlowdownTimerXML = std::round(this->xmlData->getFloat("towers.ultraIceLevin.@slowdownTimer") * Main::fps);//Number(this->xmlData.towers.ultraIceLevin.@slowdownTimer) * Main::fps);
		this->ultraIceLevinLongXML = this->xmlData->getFloat("towers.ultraIceLevin.@long");//Number(this->xmlData.towers.ultraIceLevin.@long);
		this->ultraIceLevinMaxUnitsXML = this->xmlData->getInt("towers.ultraIceLevin.@maxUnits");//int(this->xmlData.towers.ultraIceLevin.@maxUnits);
		this->ultraAddIceLevinDamageXML = this->xmlData->getFloat("towers.ultraAdditionalIceLevin.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraAdditionalIceLevin.@damage) * this->complexitySettingXML;
		this->ultraAddIceLevinIntervalXML = std::round(this->xmlData->getFloat("towers.ultraAdditionalIceLevin.@interval") * Main::fps);//Number(this->xmlData.towers.ultraAdditionalIceLevin.@interval) * Main::fps);
		this->ultraAddIceLevinDamageRadiusXML = this->xmlData->getFloat("towers.ultraAdditionalIceLevin.@damageRadius");//Number(this->xmlData.towers.ultraAdditionalIceLevin.@damageRadius);
		this->ultraAddIceLevinSlowdownTimerXML = std::round(this->xmlData->getFloat("towers.ultraAdditionalIceLevin.@slowdownInterval") * Main::fps);//Number(this->xmlData.towers.ultraAdditionalIceLevin.@slowdownInterval) * Main::fps);
		this->ultraIceStoneDamageXML = this->xmlData->getFloat("towers.ultraIceStone.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraIceStone.@damage) * this->complexitySettingXML;
		this->ultraIceStoneIntervalXML = std::round(this->xmlData->getFloat("towers.ultraIceStone.@interval") * Main::fps);//Number(this->xmlData.towers.ultraIceStone.@interval) * Main::fps);
		this->ultraIceStoneRadiusXML = this->xmlData->getFloat("towers.ultraIceStone.@radius");//Number(this->xmlData.towers.ultraIceStone.@radius);
		this->ultraIceStoneDamageRadiusXML = this->xmlData->getFloat("towers.ultraIceStone.@damageRadius");//Number(this->xmlData.towers.ultraIceStone.@damageRadius);
		this->ultraIceStoneSlowdownPowerXML = this->xmlData->getFloat("towers.ultraIceStone.@slowdownPower") / 100;//Number(this->xmlData.towers.ultraIceStone.@slowdownPower) / 100;
		this->ultraIceStoneSlowdownTimerXML = std::round(this->xmlData->getFloat("towers.ultraIceStone.@slowdownTimer") * Main::fps);//Number(this->xmlData.towers.ultraIceStone.@slowdownTimer) * Main::fps);
		this->ultraAddIceStoneDamageXML = this->xmlData->getFloat("towers.ultraAdditionalIceStone.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraAdditionalIceStone.@damage) * this->complexitySettingXML;
		this->ultraAddIceStoneIntervalXML = std::round(this->xmlData->getFloat("towers.ultraAdditionalIceStone.@interval") * Main::fps);//Number(this->xmlData.towers.ultraAdditionalIceStone.@interval) * Main::fps);
		this->ultraAddIceStoneRadiusXML = this->xmlData->getFloat("towers.ultraAdditionalIceStone.@radius");//Number(this->xmlData.towers.ultraAdditionalIceStone.@radius);
		this->ultraAddIceStoneSpacingXML = this->xmlData->getFloat("towers.ultraAdditionalIceStone.@spacing");//Number(this->xmlData.towers.ultraAdditionalIceStone.@spacing);
		this->ultraAddIceStonePowerXML = this->xmlData->getFloat("towers.ultraAdditionalIceStone.@power");//Number(this->xmlData.towers.ultraAdditionalIceStone.@power);
		this->ultraAddIceStoneSlowdownTimerXML = std::round(this->xmlData->getFloat("towers.ultraAdditionalIceStone.@slowdownTimer") * Main::fps);//Number(this->xmlData.towers.ultraAdditionalIceStone.@slowdownTimer) * Main::fps);
		this->ultraFireLevinDamageXML = this->xmlData->getFloat("towers.ultraFireLevin.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraFireLevin.@damage) * this->complexitySettingXML;
		this->ultraFireLevinIntervalXML = std::round(this->xmlData->getFloat("towers.ultraFireLevin.@interval") * Main::fps);//Number(this->xmlData.towers.ultraFireLevin.@interval) * Main::fps);
		this->ultraFireLevinRadiusXML = this->xmlData->getFloat("towers.ultraFireLevin.@radius");//Number(this->xmlData.towers.ultraFireLevin.@radius);
		this->ultraFireLevinDamageRadiusXML = this->xmlData->getFloat("towers.ultraFireLevin.@damageRadius");//Number(this->xmlData.towers.ultraFireLevin.@damageRadius);
		this->ultraAddFireLevinDamageXML = this->xmlData->getFloat("towers.ultraAdditionalFireLevin.@damage") * this->complexitySettingXML;//Number(this->xmlData.towers.ultraAdditionalFireLevin.@damage) * this->complexitySettingXML;
		this->ultraAddFireLevinIntervalXML = std::round(this->xmlData->getFloat("towers.ultraAdditionalFireLevin.@interval") * Main::fps);//Number(this->xmlData.towers.ultraAdditionalFireLevin.@interval) * Main::fps);
		this->ultraAddFireLevinRadiusXML = this->xmlData->getFloat("towers.ultraAdditionalFireLevin.@radius");//Number(this->xmlData.towers.ultraAdditionalFireLevin.@radius);
		//this->xmlLoaderLevels = NULL;
		if (this->xmlDataLevels){
			this->xmlDataLevels->~XMLConfigParser();
		}
		this->xmlDataLevels = NULL;
		this->fireSellTax = 0.6f;
		this->iceSellTax = 0.6f;
		this->stoneSellTax = 0.6f;
		this->levinSellTax = 0.6f;
		this->levinCountPlus = 0;
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem5"))
		{
			this->intervalTimerGolemXML = this->intervalTimerGolemXML - std::round(30 * 15);
			this->castGolemHealthXML = this->castGolemHealthXML * 3.5;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem4"))
		{
			this->intervalTimerGolemXML = this->intervalTimerGolemXML - std::round(30 * 10);
			this->castGolemHealthXML = std::round(this->castGolemHealthXML * 2.75);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem3"))
		{
			this->intervalTimerGolemXML = this->intervalTimerGolemXML - std::round(30 * 8);
			this->castGolemHealthXML = std::round(this->castGolemHealthXML * 2);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem2"))
		{
			this->intervalTimerGolemXML = this->intervalTimerGolemXML - std::round(30 * 5);
			this->castGolemHealthXML = std::round(this->castGolemHealthXML * 1.6);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem1"))
		{
			this->intervalTimerGolemXML = this->intervalTimerGolemXML - std::round(30 * 3);
			this->castGolemHealthXML = std::round(this->castGolemHealthXML * 1.3);
		}
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman5"))//if (Main::mainClass->saveBoxClass.gameSave.data.upgradeIceman5)
		{
			this->intervalTimerIcemanXML = this->intervalTimerIcemanXML - std::round(30 * 10);
			this->castIcemanLifeTimerXML = this->castIcemanLifeTimerXML + std::round(30 * 5);
			this->castIcemanFreezTimerXML = this->castIcemanFreezTimerXML + std::round(30 * 3);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman4"))//if (Main::mainClass->saveBoxClass.gameSave.data.upgradeIceman4)
		{
			this->intervalTimerIcemanXML = this->intervalTimerIcemanXML - std::round(30 * 7);
			this->castIcemanLifeTimerXML = this->castIcemanLifeTimerXML + std::round(30 * 4);
			this->castIcemanFreezTimerXML = this->castIcemanFreezTimerXML + std::round(30 * 2);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman3"))//if (Main::mainClass->saveBoxClass.gameSave.data.upgradeIceman3)
		{
			this->intervalTimerIcemanXML = this->intervalTimerIcemanXML - std::round(30 * 5);
			this->castIcemanLifeTimerXML = this->castIcemanLifeTimerXML + std::round(30 * 3);
			this->castIcemanFreezTimerXML = this->castIcemanFreezTimerXML + std::round(30 * 0.5);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman2"))//if (Main::mainClass->saveBoxClass.gameSave.data.upgradeIceman2)
		{
			this->intervalTimerIcemanXML = this->intervalTimerIcemanXML - std::round(30 * 3);
			this->castIcemanLifeTimerXML = this->castIcemanLifeTimerXML + std::round(30 * 2);
			this->castIcemanFreezTimerXML = this->castIcemanFreezTimerXML + std::round(30 * 0.5);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman1"))//if (Main::mainClass->saveBoxClass.gameSave.data.upgradeIceman1)
		{
			this->intervalTimerIcemanXML = this->intervalTimerIcemanXML - std::round(30 * 1);
			this->castIcemanLifeTimerXML = this->castIcemanLifeTimerXML + std::round(30 * 1);
			this->castIcemanFreezTimerXML = this->castIcemanFreezTimerXML + std::round(30 * 0);
		}
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir5"))//if (Main::mainClass->saveBoxClass.gameSave.data.upgradeAir5)
		{
			this->intervalTimerAirXML = this->intervalTimerAirXML - std::round(30 * 15);
			this->airLifeSecXML = this->airLifeSecXML + std::round(30 * 6);
			this->airPowerXML = this->airPowerXML + 8;
			this->airSpacingXML = this->airSpacingXML + 50;
			this->airWaitTimerXML = this->airWaitTimerXML + std::round(30 * 2);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir4"))//if (Main::mainClass->saveBoxClass.gameSave.data.upgradeAir4)
		{
			this->intervalTimerAirXML = this->intervalTimerAirXML - std::round(30 * 10);
			this->airLifeSecXML = this->airLifeSecXML + std::round(30 * 4);
			this->airPowerXML = this->airPowerXML + 4;
			this->airSpacingXML = this->airSpacingXML + 25;
			this->airWaitTimerXML = this->airWaitTimerXML + std::round(30 * 1);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir3"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeAir3)
		{
			this->intervalTimerAirXML = this->intervalTimerAirXML - std::round(30 * 7);
			this->airLifeSecXML = this->airLifeSecXML + std::round(30 * 3);
			this->airPowerXML = this->airPowerXML + 3;
			this->airSpacingXML = this->airSpacingXML + 15;
			this->airWaitTimerXML = this->airWaitTimerXML + std::round(30 * 1);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir2"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeAir2)
		{
			this->intervalTimerAirXML = this->intervalTimerAirXML - std::round(30 * 4);
			this->airLifeSecXML = this->airLifeSecXML + std::round(30 * 2);
			this->airPowerXML = this->airPowerXML + 2;
			this->airSpacingXML = this->airSpacingXML + 10;
			this->airWaitTimerXML = this->airWaitTimerXML + std::round(30 * 0.5);
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir1"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeAir1)
		{
			this->intervalTimerAirXML = this->intervalTimerAirXML - std::round(30 * 2);
			this->airLifeSecXML = this->airLifeSecXML + std::round(30 * 1);
			this->airPowerXML++;
			this->airSpacingXML = this->airSpacingXML + 5;
			this->airWaitTimerXML = this->airWaitTimerXML + std::round(30 * 0);
		}
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire5"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeFire5)
		{
			this->fireSellTax = this->fireSellTax + 0.1;
			this->fireTowerIntervalXML = this->fireTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveFireXML[0] = std::round(this->listOfMoveFireXML[0] * 1.1);
			this->listOfMoveFireXML[1] = std::round(this->listOfMoveFireXML[1] * 1.32);
			this->listOfMoveFireXML[2] = std::round(this->listOfMoveFireXML[2] * 1.32);
			this->listOfMoveFireXML[3] = std::round(this->listOfMoveFireXML[3] * 1.32);
			this->listOfMoveFireXML[4] = std::round(this->listOfMoveFireXML[4] * 1.32);
			this->i = 0;
			while (this->i < this->listOfFirePriceXML.size())
			{
				this->listOfFirePriceXML[this->i] = std::round(this->listOfFirePriceXML[this->i] * 0.75);
				i++;
			}
			this->listOfFireTowerDamageXML[0] = this->listOfFireTowerDamageXML[0] * 1.32;
			this->listOfFireTowerDamageXML[1] = this->listOfFireTowerDamageXML[1] * 1.32;
			this->listOfFireTowerDamageXML[2] = this->listOfFireTowerDamageXML[2] * 1.32;
			this->listOfFireTowerDamageXML[3] = this->listOfFireTowerDamageXML[3] * 1.32;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire4"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeFire4)
		{
			this->fireSellTax = this->fireSellTax + 0.1;
			this->fireTowerIntervalXML = this->fireTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveFireXML[0] = std::round(this->listOfMoveFireXML[0] * 1.1);
			this->listOfMoveFireXML[1] = std::round(this->listOfMoveFireXML[1] * 1.22);
			this->listOfMoveFireXML[2] = std::round(this->listOfMoveFireXML[2] * 1.22);
			this->listOfMoveFireXML[3] = std::round(this->listOfMoveFireXML[3] * 1.22);
			this->listOfMoveFireXML[4] = std::round(this->listOfMoveFireXML[4] * 1.22);
			this->i = 0;
			while (this->i < this->listOfFirePriceXML.size())
			{
				this->listOfFirePriceXML[this->i] = std::round(this->listOfFirePriceXML[this->i] * 0.85);
				i++;
			}
			this->listOfFireTowerDamageXML[0] = this->listOfFireTowerDamageXML[0] * 1.22;
			this->listOfFireTowerDamageXML[1] = this->listOfFireTowerDamageXML[1] * 1.22;
			this->listOfFireTowerDamageXML[2] = this->listOfFireTowerDamageXML[2] * 1.22;
			this->listOfFireTowerDamageXML[3] = this->listOfFireTowerDamageXML[3] * 1.22;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire3"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeFire3)
		{
			this->fireSellTax = this->fireSellTax + 0.1;
			this->fireTowerIntervalXML = this->fireTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveFireXML[0] = std::round(this->listOfMoveFireXML[0] * 1.05);
			this->listOfMoveFireXML[1] = std::round(this->listOfMoveFireXML[1] * 1.15);
			this->listOfMoveFireXML[2] = std::round(this->listOfMoveFireXML[2] * 1.15);
			this->listOfMoveFireXML[3] = std::round(this->listOfMoveFireXML[3] * 1.15);
			this->listOfMoveFireXML[4] = std::round(this->listOfMoveFireXML[4] * 1.15);
			this->i = 0;
			while (this->i < this->listOfFirePriceXML.size())
			{
				this->listOfFirePriceXML[this->i] = std::round(this->listOfFirePriceXML[this->i] * 0.85);
				i++;
			}
			this->listOfFireTowerDamageXML[0] = this->listOfFireTowerDamageXML[0] * 1.15;
			this->listOfFireTowerDamageXML[1] = this->listOfFireTowerDamageXML[1] * 1.15;
			this->listOfFireTowerDamageXML[2] = this->listOfFireTowerDamageXML[2] * 1.15;
			this->listOfFireTowerDamageXML[3] = this->listOfFireTowerDamageXML[3] * 1.15;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire2"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeFire2)
		{
			this->fireSellTax = this->fireSellTax + 0.1;
			this->fireTowerIntervalXML = this->fireTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveFireXML[0] = std::round(this->listOfMoveFireXML[0] * 1.05);
			this->listOfMoveFireXML[1] = std::round(this->listOfMoveFireXML[1] * 1.1);
			this->listOfMoveFireXML[2] = std::round(this->listOfMoveFireXML[2] * 1.1);
			this->listOfMoveFireXML[3] = std::round(this->listOfMoveFireXML[3] * 1.1);
			this->listOfMoveFireXML[4] = std::round(this->listOfMoveFireXML[4] * 1.1);
			this->i = 0;
			while (this->i < this->listOfFirePriceXML.size())
			{
				this->listOfFirePriceXML[this->i] = std::round(this->listOfFirePriceXML[this->i] * 0.95);
				i++;
			}
			this->listOfFireTowerDamageXML[0] = this->listOfFireTowerDamageXML[0] * 1.1;
			this->listOfFireTowerDamageXML[1] = this->listOfFireTowerDamageXML[1] * 1.1;
			this->listOfFireTowerDamageXML[2] = this->listOfFireTowerDamageXML[2] * 1.1;
			this->listOfFireTowerDamageXML[3] = this->listOfFireTowerDamageXML[3] * 1.1;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire1"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeFire1)
		{
			this->fireSellTax = this->fireSellTax + 0.1;
			this->fireTowerIntervalXML = this->fireTowerIntervalXML - std::round(30 * 0);
			this->listOfMoveFireXML[0] = std::round(this->listOfMoveFireXML[0] * 1.05);
			this->listOfMoveFireXML[1] = std::round(this->listOfMoveFireXML[1] * 1.05);
			this->listOfMoveFireXML[2] = std::round(this->listOfMoveFireXML[2] * 1.05);
			this->listOfMoveFireXML[3] = std::round(this->listOfMoveFireXML[3] * 1.05);
			this->listOfMoveFireXML[4] = std::round(this->listOfMoveFireXML[4] * 1.05);
			this->i = 0;
			while (this->i < this->listOfFirePriceXML.size())
			{

				this->listOfFirePriceXML[this->i] = std::round(this->listOfFirePriceXML[this->i] * 0.95);
				i++;
			}
			this->listOfFireTowerDamageXML[0] = this->listOfFireTowerDamageXML[0] * 1.05;
			this->listOfFireTowerDamageXML[1] = this->listOfFireTowerDamageXML[1] * 1.05;
			this->listOfFireTowerDamageXML[2] = this->listOfFireTowerDamageXML[2] * 1.05;
			this->listOfFireTowerDamageXML[3] = this->listOfFireTowerDamageXML[3] * 1.05;
		}
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce5"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeIce5)
		{
			this->iceSellTax = this->iceSellTax + 0.1;
			this->iceEffectSlowdown1XML = this->iceEffectSlowdown1XML * 1.1;
			this->iceEffectSlowdown2XML = this->iceEffectSlowdown2XML * 1.1;
			this->iceEffectSlowdown3XML = this->iceEffectSlowdown3XML * 1.1;
			this->iceEffectSlowdown4XML = this->iceEffectSlowdown4XML * 1.1;
			this->iceTowerIntervalXML = this->iceTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveIceXML[0] = std::round(this->listOfMoveIceXML[0] * 1.1);
			this->listOfMoveIceXML[1] = std::round(this->listOfMoveIceXML[1] * 1.32);
			this->listOfMoveIceXML[2] = std::round(this->listOfMoveIceXML[2] * 1.32);
			this->listOfMoveIceXML[3] = std::round(this->listOfMoveIceXML[3] * 1.32);
			this->listOfMoveIceXML[4] = std::round(this->listOfMoveIceXML[4] * 1.32);
			this->i = 0;
			while (this->i < this->listOfIcePriceXML.size())
			{
				this->listOfIcePriceXML[this->i] = std::round(this->listOfIcePriceXML[this->i] * 0.75);
				i++;
			}
			this->listOfIceTowerDamageXML[0] = this->listOfIceTowerDamageXML[0] * 1.32;
			this->listOfIceTowerDamageXML[1] = this->listOfIceTowerDamageXML[1] * 1.32;
			this->listOfIceTowerDamageXML[2] = this->listOfIceTowerDamageXML[2] * 1.32;
			this->listOfIceTowerDamageXML[3] = this->listOfIceTowerDamageXML[3] * 1.32;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce4"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeIce4)
		{
			this->iceSellTax = this->iceSellTax + 0.1;
			this->iceEffectSlowdown1XML = this->iceEffectSlowdown1XML * 1.05;
			this->iceEffectSlowdown2XML = this->iceEffectSlowdown2XML * 1.05;
			this->iceEffectSlowdown3XML = this->iceEffectSlowdown3XML * 1.05;
			this->iceEffectSlowdown4XML = this->iceEffectSlowdown4XML * 1.05;
			this->iceTowerIntervalXML = this->iceTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveIceXML[0] = std::round(this->listOfMoveIceXML[0] * 1.1);
			this->listOfMoveIceXML[1] = std::round(this->listOfMoveIceXML[1] * 1.22);
			this->listOfMoveIceXML[2] = std::round(this->listOfMoveIceXML[2] * 1.22);
			this->listOfMoveIceXML[3] = std::round(this->listOfMoveIceXML[3] * 1.22);
			this->listOfMoveIceXML[4] = std::round(this->listOfMoveIceXML[4] * 1.22);
			this->i = 0;
			while (this->i < this->listOfIcePriceXML.size())
			{
				this->listOfIcePriceXML[this->i] = std::round(this->listOfIcePriceXML[this->i] * 0.85);
				i++;
			}
			this->listOfIceTowerDamageXML[0] = this->listOfIceTowerDamageXML[0] * 1.22;
			this->listOfIceTowerDamageXML[1] = this->listOfIceTowerDamageXML[1] * 1.22;
			this->listOfIceTowerDamageXML[2] = this->listOfIceTowerDamageXML[2] * 1.22;
			this->listOfIceTowerDamageXML[3] = this->listOfIceTowerDamageXML[3] * 1.22;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce3"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeIce3)
		{
			this->iceSellTax = this->iceSellTax + 0.1;
			this->iceEffectSlowdown1XML = this->iceEffectSlowdown1XML * 1.05;
			this->iceEffectSlowdown2XML = this->iceEffectSlowdown2XML * 1.05;
			this->iceEffectSlowdown3XML = this->iceEffectSlowdown3XML * 1.05;
			this->iceEffectSlowdown4XML = this->iceEffectSlowdown4XML * 1.05;
			this->iceTowerIntervalXML = this->iceTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveIceXML[0] = std::round(this->listOfMoveIceXML[0] * 1.05);
			this->listOfMoveIceXML[1] = std::round(this->listOfMoveIceXML[1] * 1.15);
			this->listOfMoveIceXML[2] = std::round(this->listOfMoveIceXML[2] * 1.15);
			this->listOfMoveIceXML[3] = std::round(this->listOfMoveIceXML[3] * 1.15);
			this->listOfMoveIceXML[4] = std::round(this->listOfMoveIceXML[4] * 1.15);
			this->i = 0;
			while (this->i < this->listOfIcePriceXML.size())
			{ 
				this->listOfIcePriceXML[this->i] = std::round(this->listOfIcePriceXML[this->i] * 0.95);
				i++;
			}
			this->listOfIceTowerDamageXML[0] = this->listOfIceTowerDamageXML[0] * 1.15;
			this->listOfIceTowerDamageXML[1] = this->listOfIceTowerDamageXML[1] * 1.15;
			this->listOfIceTowerDamageXML[2] = this->listOfIceTowerDamageXML[2] * 1.15;
			this->listOfIceTowerDamageXML[3] = this->listOfIceTowerDamageXML[3] * 1.15;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce2"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeIce2)
		{
			this->iceSellTax = this->iceSellTax + 0.1;
			this->iceEffectSlowdown1XML = this->iceEffectSlowdown1XML * 1.05;
			this->iceEffectSlowdown2XML = this->iceEffectSlowdown2XML * 1.05;
			this->iceEffectSlowdown3XML = this->iceEffectSlowdown3XML * 1.05;
			this->iceEffectSlowdown4XML = this->iceEffectSlowdown4XML * 1.05;
			this->iceTowerIntervalXML = this->iceTowerIntervalXML - std::round(30 * 0);
			this->listOfMoveIceXML[0] = std::round(this->listOfMoveIceXML[0] * 1.05);
			this->listOfMoveIceXML[1] = std::round(this->listOfMoveIceXML[1] * 1.1);
			this->listOfMoveIceXML[2] = std::round(this->listOfMoveIceXML[2] * 1.1);
			this->listOfMoveIceXML[3] = std::round(this->listOfMoveIceXML[3] * 1.1);
			this->listOfMoveIceXML[4] = std::round(this->listOfMoveIceXML[4] * 1.1);
			this->i = 0;
			while (this->i < this->listOfIcePriceXML.size())
			{ 
				this->listOfIcePriceXML[this->i] = std::round(this->listOfIcePriceXML[this->i] * 0.95);
				i++;
			}
			this->listOfIceTowerDamageXML[0] = this->listOfIceTowerDamageXML[0] * 1.1;
			this->listOfIceTowerDamageXML[1] = this->listOfIceTowerDamageXML[1] * 1.1;
			this->listOfIceTowerDamageXML[2] = this->listOfIceTowerDamageXML[2] * 1.1;
			this->listOfIceTowerDamageXML[3] = this->listOfIceTowerDamageXML[3] * 1.1;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce1"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeIce1)
		{
			this->iceSellTax = this->iceSellTax + 0.1;
			this->iceEffectSlowdown1XML = this->iceEffectSlowdown1XML * 1;
			this->iceEffectSlowdown2XML = this->iceEffectSlowdown2XML * 1;
			this->iceEffectSlowdown3XML = this->iceEffectSlowdown3XML * 1;
			this->iceEffectSlowdown4XML = this->iceEffectSlowdown4XML * 1;
			this->iceTowerIntervalXML = this->iceTowerIntervalXML - std::round(30 * 0);
			this->listOfMoveIceXML[0] = std::round(this->listOfMoveIceXML[0] * 1.05);
			this->listOfMoveIceXML[1] = std::round(this->listOfMoveIceXML[1] * 1.05);
			this->listOfMoveIceXML[2] = std::round(this->listOfMoveIceXML[2] * 1.05);
			this->listOfMoveIceXML[3] = std::round(this->listOfMoveIceXML[3] * 1.05);
			this->listOfMoveIceXML[4] = std::round(this->listOfMoveIceXML[4] * 1.05);
			this->i = 0;
			while (this->i < this->listOfIcePriceXML.size())
			{ 
				this->listOfIcePriceXML[this->i] = std::round(this->listOfIcePriceXML[this->i] * 1);
				i++;
			}
			this->listOfIceTowerDamageXML[0] = this->listOfIceTowerDamageXML[0] * 1.05;
			this->listOfIceTowerDamageXML[1] = this->listOfIceTowerDamageXML[1] * 1.05;
			this->listOfIceTowerDamageXML[2] = this->listOfIceTowerDamageXML[2] * 1.05;
			this->listOfIceTowerDamageXML[3] = this->listOfIceTowerDamageXML[3] * 1.05;
		}
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone5"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeStone5)
		{
			this->stoneTowerIntervalXML = this->stoneTowerIntervalXML - std::round(30 * 0.2);
			this->stoneSellTax = this->stoneSellTax + 0.1;
			this->stoneEffectRadiusXML = std::round(this->stoneEffectRadiusXML * 1.1);
			this->listOfMoveStoneXML[0] = std::round(this->listOfMoveStoneXML[0] * 1.1);
			this->listOfMoveStoneXML[1] = std::round(this->listOfMoveStoneXML[1] * 1.32);
			this->listOfMoveStoneXML[2] = std::round(this->listOfMoveStoneXML[2] * 1.32);
			this->listOfMoveStoneXML[3] = std::round(this->listOfMoveStoneXML[3] * 1.32);
			this->listOfMoveStoneXML[4] = std::round(this->listOfMoveStoneXML[4] * 1.32);
			this->i = 0;
			while (this->i < this->listOfStonePriceXML.size())
			{ 
				this->listOfStonePriceXML[this->i] = std::round(this->listOfStonePriceXML[this->i] * 0.75);
				i++;
			}
			this->listOfStoneTowerDamageXML[0] = this->listOfStoneTowerDamageXML[0] * 1.32;
			this->listOfStoneTowerDamageXML[1] = this->listOfStoneTowerDamageXML[1] * 1.32;
			this->listOfStoneTowerDamageXML[2] = this->listOfStoneTowerDamageXML[2] * 1.32;
			this->listOfStoneTowerDamageXML[3] = this->listOfStoneTowerDamageXML[3] * 1.32;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone4"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeStone4)
		{
			this->stoneTowerIntervalXML = this->stoneTowerIntervalXML - std::round(30 * 0.2);
			this->stoneSellTax = this->stoneSellTax + 0.1;
			this->stoneEffectRadiusXML = std::round(this->stoneEffectRadiusXML * 1.05);
			this->listOfMoveStoneXML[0] = std::round(this->listOfMoveStoneXML[0] * 1.1);
			this->listOfMoveStoneXML[1] = std::round(this->listOfMoveStoneXML[1] * 1.22);
			this->listOfMoveStoneXML[2] = std::round(this->listOfMoveStoneXML[2] * 1.22);
			this->listOfMoveStoneXML[3] = std::round(this->listOfMoveStoneXML[3] * 1.22);
			this->listOfMoveStoneXML[4] = std::round(this->listOfMoveStoneXML[4] * 1.22);
			this->i = 0;
			while (this->i < this->listOfStonePriceXML.size())
			{ 
				this->listOfStonePriceXML[this->i] = std::round(this->listOfStonePriceXML[this->i] * 0.85);
				i++;
			}
			this->listOfStoneTowerDamageXML[0] = this->listOfStoneTowerDamageXML[0] * 1.22;
			this->listOfStoneTowerDamageXML[1] = this->listOfStoneTowerDamageXML[1] * 1.22;
			this->listOfStoneTowerDamageXML[2] = this->listOfStoneTowerDamageXML[2] * 1.22;
			this->listOfStoneTowerDamageXML[3] = this->listOfStoneTowerDamageXML[3] * 1.22;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone3"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeStone3)
		{
			this->stoneTowerIntervalXML = this->stoneTowerIntervalXML - std::round(30 * 0.2);
			this->stoneSellTax = this->stoneSellTax + 0.1;
			this->stoneEffectRadiusXML = std::round(this->stoneEffectRadiusXML * 1.05);
			this->listOfMoveStoneXML[0] = std::round(this->listOfMoveStoneXML[0] * 1.05);
			this->listOfMoveStoneXML[1] = std::round(this->listOfMoveStoneXML[1] * 1.15);
			this->listOfMoveStoneXML[2] = std::round(this->listOfMoveStoneXML[2] * 1.15);
			this->listOfMoveStoneXML[3] = std::round(this->listOfMoveStoneXML[3] * 1.15);
			this->listOfMoveStoneXML[4] = std::round(this->listOfMoveStoneXML[4] * 1.15);
			this->i = 0;
			while (this->i < this->listOfStonePriceXML.size())
			{ 
				this->listOfStonePriceXML[this->i] = std::round(this->listOfStonePriceXML[this->i] * 0.95);
				i++;
			}
			this->listOfStoneTowerDamageXML[0] = this->listOfStoneTowerDamageXML[0] * 1.15;
			this->listOfStoneTowerDamageXML[1] = this->listOfStoneTowerDamageXML[1] * 1.15;
			this->listOfStoneTowerDamageXML[2] = this->listOfStoneTowerDamageXML[2] * 1.15;
			this->listOfStoneTowerDamageXML[3] = this->listOfStoneTowerDamageXML[3] * 1.15;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone2"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeStone2)
		{
			this->stoneTowerIntervalXML = this->stoneTowerIntervalXML - std::round(30 * 0.2);
			this->stoneSellTax = this->stoneSellTax + 0.1;
			this->stoneEffectRadiusXML = std::round(this->stoneEffectRadiusXML * 1.05);
			this->listOfMoveStoneXML[0] = std::round(this->listOfMoveStoneXML[0] * 1.05);
			this->listOfMoveStoneXML[1] = std::round(this->listOfMoveStoneXML[1] * 1.1);
			this->listOfMoveStoneXML[2] = std::round(this->listOfMoveStoneXML[2] * 1.1);
			this->listOfMoveStoneXML[3] = std::round(this->listOfMoveStoneXML[3] * 1.1);
			this->listOfMoveStoneXML[4] = std::round(this->listOfMoveStoneXML[4] * 1.1);
			this->i = 0;
			while (this->i < this->listOfStonePriceXML.size())
			{ 
				this->listOfStonePriceXML[this->i] = std::round(this->listOfStonePriceXML[this->i] * 1);
				i++;
			}
			this->listOfStoneTowerDamageXML[0] = this->listOfStoneTowerDamageXML[0] * 1.1;
			this->listOfStoneTowerDamageXML[1] = this->listOfStoneTowerDamageXML[1] * 1.1;
			this->listOfStoneTowerDamageXML[2] = this->listOfStoneTowerDamageXML[2] * 1.1;
			this->listOfStoneTowerDamageXML[3] = this->listOfStoneTowerDamageXML[3] * 1.1;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeStone1)
		{
			this->stoneTowerIntervalXML = this->stoneTowerIntervalXML - std::round(30 * 0.2);
			this->stoneSellTax = this->stoneSellTax + 0;
			this->stoneEffectRadiusXML = std::round(this->stoneEffectRadiusXML * 1);
			this->listOfMoveStoneXML[0] = std::round(this->listOfMoveStoneXML[0] * 1);
			this->listOfMoveStoneXML[1] = std::round(this->listOfMoveStoneXML[1] * 1.05);
			this->listOfMoveStoneXML[2] = std::round(this->listOfMoveStoneXML[2] * 1.05);
			this->listOfMoveStoneXML[3] = std::round(this->listOfMoveStoneXML[3] * 1.05);
			this->listOfMoveStoneXML[4] = std::round(this->listOfMoveStoneXML[4] * 1.05);
			this->i = 0;
			while (this->i < this->listOfStonePriceXML.size())
			{ 
				this->listOfStonePriceXML[this->i] = std::round(this->listOfStonePriceXML[this->i] * 1);
				i++;
			}
			this->listOfStoneTowerDamageXML[0] = this->listOfStoneTowerDamageXML[0] * 1.05;
			this->listOfStoneTowerDamageXML[1] = this->listOfStoneTowerDamageXML[1] * 1.05;
			this->listOfStoneTowerDamageXML[2] = this->listOfStoneTowerDamageXML[2] * 1.05;
			this->listOfStoneTowerDamageXML[3] = this->listOfStoneTowerDamageXML[3] * 1.05;
		}
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin5"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeLevin5)
		{
			this->levinSellTax = this->levinSellTax + 0.1;
			this->levinCountPlus = this->levinCountPlus + 2;
			this->levinTowerIntervalXML = this->levinTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveLevinXML[0] = std::round(this->listOfMoveLevinXML[0] * 1.1);
			this->listOfMoveLevinXML[1] = std::round(this->listOfMoveLevinXML[1] * 1.32);
			this->listOfMoveLevinXML[2] = std::round(this->listOfMoveLevinXML[2] * 1.32);
			this->listOfMoveLevinXML[3] = std::round(this->listOfMoveLevinXML[3] * 1.32);
			this->listOfMoveLevinXML[4] = std::round(this->listOfMoveLevinXML[4] * 1.32);
			this->i = 0;
			while (this->i < this->listOfLevinPriceXML.size())
			{ 
				this->listOfLevinPriceXML[this->i] = std::round(this->listOfLevinPriceXML[this->i] * 0.75);
				i++;
			}
			this->levinEffectDamageXML = this->levinEffectDamageXML + 0.1;
			this->levinEffectRadiusXML = std::round(this->levinEffectRadiusXML * 1.1);
			this->listOfLevinTowerDamageXML[0] = this->listOfLevinTowerDamageXML[0] * 1.32;
			this->listOfLevinTowerDamageXML[1] = this->listOfLevinTowerDamageXML[1] * 1.32;
			this->listOfLevinTowerDamageXML[2] = this->listOfLevinTowerDamageXML[2] * 1.32;
			this->listOfLevinTowerDamageXML[3] = this->listOfLevinTowerDamageXML[3] * 1.32;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeLevin4)
		{
			this->levinSellTax = this->levinSellTax + 0.1;
			this->levinCountPlus++;
			this->levinTowerIntervalXML = this->levinTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveLevinXML[0] = std::round(this->listOfMoveLevinXML[0] * 1.1);
			this->listOfMoveLevinXML[1] = std::round(this->listOfMoveLevinXML[1] * 1.22);
			this->listOfMoveLevinXML[2] = std::round(this->listOfMoveLevinXML[2] * 1.22);
			this->listOfMoveLevinXML[3] = std::round(this->listOfMoveLevinXML[3] * 1.22);
			this->listOfMoveLevinXML[4] = std::round(this->listOfMoveLevinXML[4] * 1.22);
			this->i = 0;
			while (this->i < this->listOfLevinPriceXML.size())
			{ 
				this->listOfLevinPriceXML[this->i] = std::round(this->listOfLevinPriceXML[this->i] * 0.85);
				i++;
			}
			this->levinEffectDamageXML = this->levinEffectDamageXML + 0.1;
			this->levinEffectRadiusXML = std::round(this->levinEffectRadiusXML * 1.1);
			this->listOfLevinTowerDamageXML[0] = this->listOfLevinTowerDamageXML[0] * 1.22;
			this->listOfLevinTowerDamageXML[1] = this->listOfLevinTowerDamageXML[1] * 1.22;
			this->listOfLevinTowerDamageXML[2] = this->listOfLevinTowerDamageXML[2] * 1.22;
			this->listOfLevinTowerDamageXML[3] = this->listOfLevinTowerDamageXML[3] * 1.22;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeLevin4)
		{
			this->levinSellTax = this->levinSellTax + 0.1;
			this->levinCountPlus++;
			this->levinTowerIntervalXML = this->levinTowerIntervalXML - std::round(30 * 0.2);
			this->listOfMoveLevinXML[0] = std::round(this->listOfMoveLevinXML[0] * 1.1);
			this->listOfMoveLevinXML[1] = std::round(this->listOfMoveLevinXML[1] * 1.15);
			this->listOfMoveLevinXML[2] = std::round(this->listOfMoveLevinXML[2] * 1.15);
			this->listOfMoveLevinXML[3] = std::round(this->listOfMoveLevinXML[3] * 1.15);
			this->listOfMoveLevinXML[4] = std::round(this->listOfMoveLevinXML[4] * 1.15);
			this->i = 0;
			while (this->i < this->listOfLevinPriceXML.size())
			{ 
				this->listOfLevinPriceXML[this->i] = std::round(this->listOfLevinPriceXML[this->i] * 0.85);
				i++;
			}
			this->levinEffectDamageXML = this->levinEffectDamageXML + 0;
			this->levinEffectRadiusXML = std::round(this->levinEffectRadiusXML * 1);
			this->listOfLevinTowerDamageXML[0] = this->listOfLevinTowerDamageXML[0] * 1.15;
			this->listOfLevinTowerDamageXML[1] = this->listOfLevinTowerDamageXML[1] * 1.15;
			this->listOfLevinTowerDamageXML[2] = this->listOfLevinTowerDamageXML[2] * 1.15;
			this->listOfLevinTowerDamageXML[3] = this->listOfLevinTowerDamageXML[3] * 1.15;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeLevin4)
		{
			this->levinSellTax = this->levinSellTax + 0.1;
			this->levinCountPlus++;
			this->levinTowerIntervalXML = this->levinTowerIntervalXML - std::round(30 * 0);
			this->listOfMoveLevinXML[0] = std::round(this->listOfMoveLevinXML[0] * 1.1);
			this->listOfMoveLevinXML[1] = std::round(this->listOfMoveLevinXML[1] * 1.1);
			this->listOfMoveLevinXML[2] = std::round(this->listOfMoveLevinXML[2] * 1.1);
			this->listOfMoveLevinXML[3] = std::round(this->listOfMoveLevinXML[3] * 1.1);
			this->listOfMoveLevinXML[4] = std::round(this->listOfMoveLevinXML[4] * 1.1);
			this->i = 0;
			while (this->i < this->listOfLevinPriceXML.size())
			{ 
				this->listOfLevinPriceXML[this->i] = std::round(this->listOfLevinPriceXML[this->i] * 0.95);
				i++;
			}
			this->levinEffectDamageXML = this->levinEffectDamageXML + 0;
			this->levinEffectRadiusXML = std::round(this->levinEffectRadiusXML * 1);
			this->listOfLevinTowerDamageXML[0] = this->listOfLevinTowerDamageXML[0] * 1.1;
			this->listOfLevinTowerDamageXML[1] = this->listOfLevinTowerDamageXML[1] * 1.1;
			this->listOfLevinTowerDamageXML[2] = this->listOfLevinTowerDamageXML[2] * 1.1;
			this->listOfLevinTowerDamageXML[3] = this->listOfLevinTowerDamageXML[3] * 1.1;
		}
		else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))//if (Main::mainClass->saveBoxClass->gameSave.data.upgradeLevin4)
		{
			this->levinSellTax = this->levinSellTax + 0.1;
			this->levinCountPlus = this->levinCountPlus + 0;
			this->levinTowerIntervalXML = this->levinTowerIntervalXML - std::round(30 * 0);
			this->listOfMoveLevinXML[0] = std::round(this->listOfMoveLevinXML[0] * 1);
			this->listOfMoveLevinXML[1] = std::round(this->listOfMoveLevinXML[1] * 1.05);
			this->listOfMoveLevinXML[2] = std::round(this->listOfMoveLevinXML[2] * 1.05);
			this->listOfMoveLevinXML[3] = std::round(this->listOfMoveLevinXML[3] * 1.05);
			this->listOfMoveLevinXML[4] = std::round(this->listOfMoveLevinXML[4] * 1.05);
			this->i = 0;
			while (this->i < this->listOfLevinPriceXML.size())
			{ 
				this->listOfLevinPriceXML[this->i] = std::round(this->listOfLevinPriceXML[this->i] * 1);
				i++;
			}
			this->levinEffectDamageXML = this->levinEffectDamageXML + 0;
			this->levinEffectRadiusXML = std::round(this->levinEffectRadiusXML * 1);
			this->listOfLevinTowerDamageXML[0] = this->listOfLevinTowerDamageXML[0] * 1.05;
			this->listOfLevinTowerDamageXML[1] = this->listOfLevinTowerDamageXML[1] * 1.05;
			this->listOfLevinTowerDamageXML[2] = this->listOfLevinTowerDamageXML[2] * 1.05;
			this->listOfLevinTowerDamageXML[3] = this->listOfLevinTowerDamageXML[3] * 1.05;
		}
		return;
	}// end function
	 

	void ReadXML::loadXMLLevels(string param1)
	{
		if(this->xmlDataLevels){
			this->xmlDataLevels->~XMLConfigParser();
		}
		this->xmlDataLevels = new XMLConfigParser(param1, param1,true);
		//if (param1 == "levels/level1.xml")
		//{
		//	
		//}
		//else if (param1 == "levels/level2.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level3.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level4.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level5.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level6.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level7.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level8.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level9.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level10.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level11.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level12.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level13.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level14.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levels/level15.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level1.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level2.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level3.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level4.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level5.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level6.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level7.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level8.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level9.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level10.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level11.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level12.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level13.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level14.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		//else if (param1 == "levelsSurvival/level15.xml")
		//{
		//	this->xmlDataLevels = new XML();
		//}
		this->readXMLLevels();
		return;
	}// end function

	void ReadXML::readXMLLevels()
	{
		//Main::mainClass->worldClass->wavesClass->listOfWaves[0].wd[0].
		//Main::mainClass->worldClass.wavesClass= new engine::Waves();
		//Main::mainClass->worldClass.wavesClass.listOfWaves[0] = [];
		//Main::mainClass->worldClass.wavesClass.listOfWaves[0][0] = [0, []];
		this->strategies = 0;
		vector<tinyxml2::XMLElement *> strategy1 = this->xmlDataLevels->getChildList("strategy1");
		if (strategy1.size()) //if (this->xmlDataLevels.strategy1.length() > 0) //this->xmlData->getInt("cost.stone.@step38");
		{
			this->strategies++;
		}
		vector<tinyxml2::XMLElement *> strategy2 = this->xmlDataLevels->getChildList("strategy2");
		if (strategy2.size() > 0)
		{
			this->strategies++;
		}
		vector<tinyxml2::XMLElement *> strategy3 = this->xmlDataLevels->getChildList("strategy3");
		if (strategy3.size() > 0)
		{
			this->strategies++;
		}
		vector<tinyxml2::XMLElement *> waveSettings = this->xmlDataLevels->getChildList("strategy1.waveSettings");
		this->tempObject = waveSettings.size();// this->xmlDataLevels.strategy1.waveSettings.length();
		this->i = 1;
		while (this->i <= this->tempObject)
		{
			Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][0].value = this->xmlDataLevels->getFloat(waveSettings.at(i-1), "@delay") * Main::fps;
			//[int(Number(this->xmlDataLevels.strategy1.waveSettings[(this->i - 1)].@delay) * Main::fps),[]];
			//Main.mainClass.worldClass.wavesClass.listOfWaves[0][this.i] = [int(Number(this.xmlDataLevels.strategy1.waveSettings[(this.i - 1)].@delay) * Main::fps), []];
			i++;
		}
		vector<tinyxml2::XMLElement *> waves = this->xmlDataLevels->getChildList("strategy1.wave");
		this->tempObject = waves.size();// this->xmlDataLevels.strategy1.wave.length();
		this->i = 0;
		while (this->i < this->tempObject)
		{
			Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][0].value = this->xmlDataLevels->getFloat(waves.at(i), "@startDelay") * Main::fps;
				//int(Number(this->xmlDataLevels.strategy1.wave[this->i].@startDelay) * Main::fps);
			//Main::mainClass->worldClass->wavesClass->listOfWaves[0].d[this->i][1][1] = [];
			this->j = 0;
			vector<tinyxml2::XMLElement *> enemys = this->xmlDataLevels->getChildList(waves.at(i), "enemy");
			while (this->j < enemys.size())// this->xmlDataLevels.strategy1.wave[this->i].enemy.length())
			{
				//Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j] = [];
				Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][0] = this->xmlDataLevels->getInt(enemys.at(j), "@typeUnit");
				//int(this->xmlDataLevels.strategy1.wave[this->i].enemy[this->j].@typeUnit);
				Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][1] = this->xmlDataLevels->getInt(enemys.at(j), "@count");
				//int(this->xmlDataLevels.strategy1.wave[this->i].enemy[this->j].@count);
				Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][2] = std::round(this->xmlDataLevels->getFloat(enemys.at(j), "@interval") * Main::fps);
				// std::round(Number(this->xmlDataLevels.strategy1.wave[this->i].enemy[this->j].@interval) * Main::fps);
				Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][3] = this->xmlDataLevels->getInt(enemys.at(j), "@way");
				//int(this->xmlDataLevels.strategy1.wave[this->i].enemy[this->j].@way);
				Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][4] = this->xmlDataLevels->getInt(enemys.at(j), "@path");
				//int(this->xmlDataLevels.strategy1.wave[this->i].enemy[this->j].@path);
				Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][5] = this->xmlDataLevels->getInt(waves.at(i), "@replacement");
				//int(this->xmlDataLevels.strategy1.wave[this->i].@replacement);
				Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][6] = this->xmlDataLevels->getInt(enemys.at(j), "@gate");
				//int(this->xmlDataLevels.strategy1.wave[this->i].enemy[this->j].@gate);
				int replacement = this->xmlDataLevels->getInt(enemys.at(j), "@replacement");
				if (replacement > 0)
				{
					Main::mainClass->worldClass->wavesClass->listOfWaves[0][this->i][1][1][this->j][5] = replacement;
					//int(this->xmlDataLevels.strategy1.wave[this->i].enemy[this->j].@replacement);
				}
				j++;
			}
			i++;
		}
		if (this->strategies > 1)
		{
			//Main::mainClass->worldClass.wavesClass.listOfWaves[1] = [];
			vector<tinyxml2::XMLElement *> waves = this->xmlDataLevels->getChildList("strategy2.wave");
			this->tempObject = waves.size();// this->xmlDataLevels.strategy2.wave.length();
			this->i = 0;
			while (this->i < this->tempObject)
			{
				//Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i] = [0, []];
				Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][0] = this->xmlDataLevels->getFloat(waves.at(i), "@startDelay") * Main::fps;
					// int(Number(this->xmlDataLevels.strategy2.wave[this->i].@startDelay) * Main::fps);
				//Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1] = [];
				this->j = 0;
				vector<tinyxml2::XMLElement *> enemys = this->xmlDataLevels->getChildList(waves.at(i), "enemy");
				while (this->j < enemys.size())// this->xmlDataLevels.strategy2.wave[this->i].enemy.length())
				{
					//Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j] = [];
					Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][0] = this->xmlDataLevels->getInt(enemys.at(j), "@typeUnit"); 
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@typeUnit);
					Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][1] = this->xmlDataLevels->getInt(enemys.at(j), "@count"); 
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@count);
					Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][2] = std::round(this->xmlDataLevels->getFloat(enemys.at(j), "@interval") * Main::fps);
					//std::round(Number(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@interval) * Main::fps);
					Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][3] = this->xmlDataLevels->getInt(enemys.at(j), "@way"); 
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@way);
					Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][4] = this->xmlDataLevels->getInt(enemys.at(j), "@path"); 
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@path);
					Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][5] = this->xmlDataLevels->getInt(waves.at(i), "@replacement");
					//int(this->xmlDataLevels.strategy2.wave[this->i].@replacement);
					Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][6] = this->xmlDataLevels->getInt(enemys.at(j), "@gate"); 
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@gate);
					int replacement = this->xmlDataLevels->getInt(enemys.at(j), "@replacement");
					if (replacement > 0)
					{
						Main::mainClass->worldClass->wavesClass->listOfWaves[1][this->i][1][1][this->j][5] = replacement;
							//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@replacement);
					}
					j++;
				}
				i++;
			}
		}
		if (this->strategies > 2)
		{
			//Main::mainClass->worldClass.wavesClass.listOfWaves[2] = [];
			vector<tinyxml2::XMLElement *> waves = this->xmlDataLevels->getChildList("strategy3.wave");
			this->tempObject = waves.size();// this->xmlDataLevels.strategy3.wave.length();
			this->i = 0;
			while (this->i < this->tempObject)
			{
				Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][0] = 0;
				Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][0] = this->xmlDataLevels->getFloat(waves.at(i), "@startDelay")*30;
				//Main::mainClass->worldClass.wavesClass.listOfWaves[2][this->i] = [0, []];
				//Main::mainClass->worldClass.wavesClass.listOfWaves[2][this->i][1][0] = int(Number(this->xmlDataLevels.strategy3.wave[this->i].@startDelay) * Main::fps);
				//Main::mainClass->worldClass.wavesClass.listOfWaves[2][this->i][1][1] = [];
				this->j = 0;
				vector<tinyxml2::XMLElement *> enemys = this->xmlDataLevels->getChildList(waves.at(i), "enemy");
				while (this->j < enemys.size())
				{
					//Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j] = [];
					Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][0] = this->xmlDataLevels->getInt(enemys.at(j), "@typeUnit");
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@typeUnit);
					Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][1] = this->xmlDataLevels->getInt(enemys.at(j), "@count");
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@count);
					Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][2] = std::round(this->xmlDataLevels->getFloat(enemys.at(j), "@interval") * Main::fps);
					//std::round(Number(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@interval) * Main::fps);
					Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][3] = this->xmlDataLevels->getInt(enemys.at(j), "@way");
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@way);
					Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][4] = this->xmlDataLevels->getInt(enemys.at(j), "@path");
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@path);
					Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][5] = this->xmlDataLevels->getInt(waves.at(i), "@replacement");
					//int(this->xmlDataLevels.strategy2.wave[this->i].@replacement);
					Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][6] = this->xmlDataLevels->getInt(enemys.at(j), "@gate");
					//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@gate);
					int replacement = this->xmlDataLevels->getInt(enemys.at(j), "@replacement");
					if (replacement > 0)
					{
						Main::mainClass->worldClass->wavesClass->listOfWaves[2][this->i][1][1][this->j][5] = replacement;
						//int(this->xmlDataLevels.strategy2.wave[this->i].enemy[this->j].@replacement);
					} 
					j++;
				}
				i++;
			}
		}
		Main::mainClass->worldClass->wavesClass->maxWaves = Main::mainClass->worldClass->wavesClass->listOfWaves[0].size();
		//Main::mainClass->worldClass->wavesClass->maxWaves = Main::mainClass->worldClass->wavesClass->listOfWaves[0].length;
		if (this->strategies > 0)
		{
			if (Main::mainClass->worldClass->wavesClass->listOfWaves[0].size() > 0)
			{
				if (Main::mainClass->worldClass->wavesClass->listOfWaves[0][0].size() > 0)
				{
					if (Main::mainClass->worldClass->wavesClass->listOfWaves[0][0][1].size() > 0)
					{
						if (Main::mainClass->worldClass->wavesClass->listOfWaves[0][0][1][1].size() > 0)
						{
							if (Main::mainClass->worldClass->wavesClass->listOfWaves[0][0][1][1][0].size() > 0)
							{
								Main::mainClass->worldClass->pointer1->setVisible(true);
							}
						}
					}
				}
			}
		}
		if (this->strategies > 1)
		{
			if (Main::mainClass->worldClass->wavesClass->listOfWaves[1].size() > 0)
			{
				if (Main::mainClass->worldClass->wavesClass->listOfWaves[1][0].size() > 0)
				{
					if (Main::mainClass->worldClass->wavesClass->listOfWaves[1][0][1].size() > 0)
					{
						if (Main::mainClass->worldClass->wavesClass->listOfWaves[1][0][1][1].size() > 0)
						{
							if (Main::mainClass->worldClass->wavesClass->listOfWaves[1][0][1][1][0].size() > 0)
							{
								Main::mainClass->worldClass->pointer2->setVisible(true);
							}
						}
					}
				}
			}
		}
		Main::mainClass->worldClass->money = this->xmlDataLevels->getInt("settings.@money");
		Main::mainClass->worldClass->bonusMoney = this->xmlDataLevels->getInt("settings.@bonus"); 
		this->testTowerStep = this->xmlDataLevels->getInt("settings.testing.@towerStep");//int(this->xmlDataLevels.settings.testing.@towerStep);
		this->testFireStep = this->xmlDataLevels->getInt("settings.testing.@fireStep");//int(this->xmlDataLevels.settings.testing.@fireStep);
		this->testIceStep = this->xmlDataLevels->getInt("settings.testing.@iceStep");//int(this->xmlDataLevels.settings.testing.@iceStep);
		this->testStoneStep = this->xmlDataLevels->getInt("settings.testing.@stoneStep");//int(this->xmlDataLevels.settings.testing.@stoneStep);
		this->testLevinStep = this->xmlDataLevels->getInt("settings.testing.@levinStep");//int(this->xmlDataLevels.settings.testing.@levinStep);
		this->archiveSphereBlock = this->xmlDataLevels->getInt("settings.sphere.@archiveSphereBlock");//int(this->xmlDataLevels.settings.sphere.@archiveSphereBlock);
		this->towerSlotBlock = this->xmlDataLevels->getInt("settings.sphere.@towerSlotBlock");//int(this->xmlDataLevels.settings.sphere.@towerSlotBlock);
		this->ultraTower1Block = this->xmlDataLevels->getInt("settings.sphere.@ultraTower1Block");//int(this->xmlDataLevels.settings.sphere.@ultraTower1Block);
		this->ultraTower2Block = this->xmlDataLevels->getInt("settings.sphere.@ultraTower2Block");//int(this->xmlDataLevels.settings.sphere.@ultraTower2Block);
		this->ultraTower3Block = this->xmlDataLevels->getInt("settings.sphere.@ultraTower3Block");//int(this->xmlDataLevels.settings.sphere.@ultraTower3Block);
		this->ultraTower4Block = this->xmlDataLevels->getInt("settings.sphere.@ultraTower4Block");//int(this->xmlDataLevels.settings.sphere.@ultraTower4Block);
		this->ultraTower1UpgrBlock = this->xmlDataLevels->getInt("settings.sphere.@ultraTower1UpgrBlock");//int(this->xmlDataLevels.settings.sphere.@ultraTower1UpgrBlock);
		this->ultraTower2UpgrBlock = this->xmlDataLevels->getInt("settings.sphere.@ultraTower2UpgrBlock");//int(this->xmlDataLevels.settings.sphere.@ultraTower2UpgrBlock);
		this->ultraTower3UpgrBlock = this->xmlDataLevels->getInt("settings.sphere.@ultraTower3UpgrBlock");//int(this->xmlDataLevels.settings.sphere.@ultraTower3UpgrBlock);
		this->ultraTower4UpgrBlock = this->xmlDataLevels->getInt("settings.sphere.@ultraTower4UpgrBlock");//int(this->xmlDataLevels.settings.sphere.@ultraTower4UpgrBlock);
		
		vector<tinyxml2::XMLElement *> portalsFires = this->xmlDataLevels->getChildList("settings.portals.fire.location");
		this->tempObject = portalsFires.size();// this->xmlDataLevels.settings.portals.fire.location.length();
		this->listOfFirePortals.clear();
		this->i = 0;
		while (this->i < this->tempObject)
		{ 
			//this->listOfFirePortals[this->i] = [];
			this->listOfFirePortals[this->i][0] = this->xmlDataLevels->getFloat(portalsFires.at(i),"@path");
			//(Number(this->xmlDataLevels.settings.portals.fire.location[this->i].@path));
			this->listOfFirePortals[this->i][1] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@road"); 
			//.push(int(this->xmlDataLevels.settings.portals.fire.location[this->i].@road));
			this->listOfFirePortals[this->i][2] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@way");
			//.push(int(this->xmlDataLevels.settings.portals.fire.location[this->i].@way));
			this->listOfFirePortals[this->i][3] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@x");
			//.push(Number(this->xmlDataLevels.settings.portals.fire.location[this->i].@x));
			this->listOfFirePortals[this->i][4] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@y");
			//.push(Number(this->xmlDataLevels.settings.portals.fire.location[this->i].@y));
			i++;
		}
		portalsFires = this->xmlDataLevels->getChildList("settings.portals.ice.location");
		this->tempObject = portalsFires.size();// this->xmlDataLevels.settings.portals.ice.location.length();
		this->listOfIcePortals.clear();
		this->i = 0;
		while (this->i < this->tempObject)
		{ 
			//this->listOfIcePortals[this->i] = [];
			this->listOfIcePortals[this->i][0] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@path");
			//.push(Number(this->xmlDataLevels.settings.portals.ice.location[this->i].@path));
			this->listOfIcePortals[this->i][1] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@road");
			//.push(int(this->xmlDataLevels.settings.portals.ice.location[this->i].@road));
			this->listOfIcePortals[this->i][2] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@way");
			//.push(int(this->xmlDataLevels.settings.portals.ice.location[this->i].@way));
			this->listOfIcePortals[this->i][3] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@x");
			//.push(Number(this->xmlDataLevels.settings.portals.ice.location[this->i].@x));
			this->listOfIcePortals[this->i][4] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@y");
			//.push(Number(this->xmlDataLevels.settings.portals.ice.location[this->i].@y));
			i++;
		}
		portalsFires = this->xmlDataLevels->getChildList("settings.portals.stone.location");
		this->tempObject = portalsFires.size();// this->xmlDataLevels.settings.portals.stone.location.length();
		this->listOfStonePortals.clear(); 
		this->i = 0;
		while (this->i < this->tempObject)
		{ 
			//this->listOfStonePortals[this->i] = [];
			this->listOfStonePortals[this->i][0] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@path");
			//.push(Number(this->xmlDataLevels.settings.portals.stone.location[this->i].@path));
			this->listOfStonePortals[this->i][1] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@road");
			//.push(int(this->xmlDataLevels.settings.portals.stone.location[this->i].@road));
			this->listOfStonePortals[this->i][2] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@way");
			//.push(int(this->xmlDataLevels.settings.portals.stone.location[this->i].@way));
			this->listOfStonePortals[this->i][3] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@x");
			//.push(Number(this->xmlDataLevels.settings.portals.stone.location[this->i].@x));
			this->listOfStonePortals[this->i][4] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@y");
			//.push(Number(this->xmlDataLevels.settings.portals.stone.location[this->i].@y));
			i++;
		}portalsFires = this->xmlDataLevels->getChildList("settings.portals.levin.location");
		this->tempObject = portalsFires.size();// this->xmlDataLevels.settings.portals.levin.location.length();
		this->listOfLevinPortals.clear();
		this->i = 0;
		while (this->i < this->tempObject)
		{
			//this->listOfLevinPortals[this->i] = [];
			this->listOfLevinPortals[this->i][0] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@path");
			//.push(Number(this->xmlDataLevels.settings.portals.levin.location[this->i].@path));
			this->listOfLevinPortals[this->i][1] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@road");
			//.push(int(this->xmlDataLevels.settings.portals.levin.location[this->i].@road));
			this->listOfLevinPortals[this->i][2] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@way");
			//.push(int(this->xmlDataLevels.settings.portals.levin.location[this->i].@way));
			this->listOfLevinPortals[this->i][3] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@x");
			//.push(Number(this->xmlDataLevels.settings.portals.levin.location[this->i].@x));
			this->listOfLevinPortals[this->i][4] = this->xmlDataLevels->getFloat(portalsFires.at(i), "@y");
			//.push(Number(this->xmlDataLevels.settings.portals.levin.location[this->i].@y));
			i++;
		}
		if (Main::mainClass->saveBoxClass->getIntValue("complexityLevel") <= 1)//if (Main::mainClass->saveBoxClass->gameSave.data.complexityLevel == 1)
		{
			this->complexitySettingXML = this->xmlDataLevels->getFloat("settings.complexity.@easy") / 100 ;// Number(this->xmlDataLevels.settings.complexity.@easy) / 100;
		}
		else if (Main::mainClass->saveBoxClass->getIntValue("complexityLevel") == 2)//if (Main::mainClass->saveBoxClass.gameSave.data.complexityLevel == 2)
		{
			this->complexitySettingXML = this->xmlDataLevels->getFloat("settings.complexity.@normal") / 100;// Number(this->xmlDataLevels.settings.complexity.@normal) / 100;
		}
		else if (Main::mainClass->saveBoxClass->getIntValue("complexityLevel") == 3)//if (Main::mainClass->saveBoxClass.gameSave.data.complexityLevel == 3)
		{
			this->complexitySettingXML = this->xmlDataLevels->getFloat("settings.complexity.@hard") / 100;// Number(this->xmlDataLevels.settings.complexity.@hard) / 100;
		}
		else if (Main::mainClass->saveBoxClass->getIntValue("complexityLevel") == 4)//if (Main::mainClass->saveBoxClass.gameSave.data.complexityLevel == 4)
		{
			this->complexitySettingXML = 1;
			this->autoStartCounter = std::round(this->xmlDataLevels->getFloat("settings.@autoStartTimer")  * Main::fps); // Number(this->xmlDataLevels.settings.@autoStartTimer)
		}
		//this->xmlLoaderLevels = null;
		this->xmlDataLevels->~XMLConfigParser();
		this->xmlDataLevels = NULL;
		this->loadXMLData();
		return;
	}// end function

}
