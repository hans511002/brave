#include "BaseHeaders.h"
#include "rapidjson/stringbuffer.h"
#include "saveBox.h"
//#include "MainClass.h"

namespace sys
{
    //存储系统配置, 登录信息等
    Config sysConf;
	Config::Config() {
		init();
	}
	int Config::init() {
		if (file.empty()) {
			systemConfig.SetObject();
			return 1;
		}
		else {
			int res=JsonUtil::readFile(&systemConfig, file);
			if (res != 0) {
				systemConfig.SetObject();
			}
			return res;
		}
	};

	void Config::save() {
		JsonUtil::writeFile(&systemConfig, file);
	}
	Config::Config(string file, bool savet ) {
		setSave(file, savet);
	}; 
	int Config::setSave(string file, bool savet) {
		this->file = file;
		this->savett = savet;
		return init(); 
	};

	SaveBox::SaveBox() :maxStars(63), playLevel(1)
	{
		//Document d;
		//d.Parse<0>("");
		//Value & ques = d["questions"];
		gameSave1 = new rapidjson::Document();
		gameSave2 = new rapidjson::Document();
		gameSave3 = new rapidjson::Document();
		gameSave4 = new rapidjson::Document();
		gameSave5 = new rapidjson::Document();
		gameSave6 = new rapidjson::Document();
		string wrPath = FileUtils::getInstance()->getWritablePath(); 
		if (JsonUtil::readFile(this->gameSave1, wrPath + "/brave1.json") != 0) {
			gameSave1->SetObject();
		}
		if (JsonUtil::readFile(this->gameSave2, wrPath + "/brave2.json") != 0) {
			gameSave2->SetObject();
		}
		if (JsonUtil::readFile(this->gameSave3, wrPath + "/brave3.json") != 0) {
			gameSave3->SetObject();
		}
		//net get
		gameSave4->SetObject();
		gameSave5->SetObject();
		gameSave6->SetObject();
		gameSave = gameSave1;
		checkSaves(1);
		//SetValueByPointer(d, "/project", "RapidJSON");
		//SetValueByPointer(d, "/stars", 10);
		//if (Value* stars = GetValueByPointer(d, "/stars"))
		//	stars->SetInt(stars->GetInt() + 1);
		//CreateValueByPointer(d, "/a/b/0");
		//Value& hello = GetValueByPointerWithDefault(d, "/hello", "world");
		//Value x("C++");
		//SwapValueByPointer(d, "/hello", x);
		//bool success = EraseValueByPointer(d, "/a");
		//assert(success);
	};
	SaveBox::~SaveBox() {
		delete gameSave1, gameSave2, gameSave3, gameSave4, gameSave5, gameSave6;
		gameSave1 = gameSave2 = gameSave3 = gameSave4 = gameSave5 = gameSave6 = NULL;
	}

	void  SaveBox::checkSaves(int param1)
	{
		if(param1 == 1)
			this->gameSave = this->gameSave1;
		else if(param1 == 2)
			this->gameSave = this->gameSave2;
		else if(param1 == 3)
			this->gameSave = this->gameSave3;
		else if(param1 == 4)
			this->gameSave = this->gameSave4;
		else if(param1 == 5)
			this->gameSave = this->gameSave5;
		else if(param1 == 6)
			this->gameSave = this->gameSave6;
		this->setValue("saveIndex", param1);
		if(!this->getBoolValue("haveSave"))
		{
			this->setValue("haveSave", true);
			this->setValue("openLevels", 0, 1);
			for(size_t i = 1; i < 15; i++)
				this->setValue("openLevels", i, 0);
			//this->gameSave.data.openLevels = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

			for(size_t i = 0; i < 15; i++)
				this->setValue("starsOfLevels", i, 0);
			//this->gameSave.data.starsOfLevels = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
			for(size_t i = 0; i < 15; i++)
				this->setValue("levelsFinish", i, 0);
			//this->gameSave.data.levelsFinish = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

			this->setValue("quality", "high");//this->gameSave.data.quality = "high";
			this->setValue("autoPause", true); //this->gameSave.data.autoPause = true;
			for(size_t i = 0; i < 33; i++)
				this->setValue("firstViewEnemies", i, 0);
			//this->gameSave.data.firstViewEnemies = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
			this->setValue("firstViewTowers", 0, 1);
			for(size_t i = 1; i < 8; i++)
				this->setValue("firstViewTowers", i, 0);//this->gameSave.data.firstViewTowers = [1, 0, 0, 0, 0, 0, 0, 0];
			this->setValue("complexityLevel", 2);//				this->gameSave.data.complexityLevel = 2;
			this->setValue("oldComplexityLevel", 2);//this->gameSave.data.oldComplexityLevel = 2;
			this->setValue("newLevel", 0);//this->gameSave.data.newLevel = 0;
			this->setValue("newStarsForLevel", 0);//this->gameSave.data.newStarsForLevel = 0;
			this->setValue("difficultyLevel", false);//this->gameSave.data.difficultyLevel = false;
			this->setValue("saveNo", param1);//this->gameSave.data.saveNo = param1;
			if(param1 <= 3)
			{
				this->setValue("type", "local");//this->gameSave.data.type = "local";
				this->setValue("stars", 0);//this->gameSave.data.stars = 0;
			}
			else
			{
				this->setValue("type", "site"); //this->gameSave.data.type = "site";
				this->setValue("stars", 3); //this->gameSave.data.stars = 3;
			}
			this->setValue("firstRC", false);//this->gameSave.data.firstRC = false;
			this->setValue("firstClickKeepAll", false);//this->gameSave.data.firstClickKeepAll = false;
			this->setValue("upgradeGolem1", false);//this->gameSave.data.upgradeGolem1 = false;
			this->setValue("upgradeGolem2", false);//this->gameSave.data.upgradeGolem2 = false;
			this->setValue("upgradeGolem3", false);//this->gameSave.data.upgradeGolem3 = false;
			this->setValue("upgradeGolem4", false);//this->gameSave.data.upgradeGolem4 = false;
			this->setValue("upgradeGolem5", false);//this->gameSave.data.upgradeGolem5 = false;
			this->setValue("upgradeIceman1", false);//this->gameSave.data.upgradeIceman1 = false;
			this->setValue("upgradeIceman2", false);//this->gameSave.data.upgradeIceman2 = false;
			this->setValue("upgradeIceman3", false);//this->gameSave.data.upgradeIceman3 = false;
			this->setValue("upgradeIceman4", false);//this->gameSave.data.upgradeIceman4 = false;
			this->setValue("upgradeIceman5", false);//this->gameSave.data.upgradeIceman5 = false;
			this->setValue("upgradeAir1", false);//this->gameSave.data.upgradeAir1 = false;
			this->setValue("upgradeAir2", false);//this->gameSave.data.upgradeAir2 = false;
			this->setValue("upgradeAir3", false);//this->gameSave.data.upgradeAir3 = false;
			this->setValue("upgradeAir4", false);//this->gameSave.data.upgradeAir4 = false;
			this->setValue("upgradeAir5", false);//this->gameSave.data.upgradeAir5 = false;
			this->setValue("upgradeFire1", false);//this->gameSave.data.upgradeFire1 = false;
			this->setValue("upgradeFire2", false);//this->gameSave.data.upgradeFire2 = false;
			this->setValue("upgradeFire3", false);//this->gameSave.data.upgradeFire3 = false;
			this->setValue("upgradeFire4", false);//this->gameSave.data.upgradeFire4 = false;
			this->setValue("upgradeFire5", false);//this->gameSave.data.upgradeFire5 = false;
			this->setValue("upgradeIce1", false);//this->gameSave.data.upgradeIce1 = false;
			this->setValue("upgradeIce2", false);//this->gameSave.data.upgradeIce2 = false;
			this->setValue("upgradeIce3", false);//this->gameSave.data.upgradeIce3 = false;
			this->setValue("upgradeIce4", false);//this->gameSave.data.upgradeIce4 = false;
			this->setValue("upgradeIce5", false);//this->gameSave.data.upgradeIce5 = false;
			this->setValue("upgradeStone1", false);//this->gameSave.data.upgradeStone1 = false;
			this->setValue("upgradeStone2", false);//this->gameSave.data.upgradeStone2 = false;
			this->setValue("upgradeStone3", false);//this->gameSave.data.upgradeStone3 = false;
			this->setValue("upgradeStone4", false);//this->gameSave.data.upgradeStone4 = false;
			this->setValue("upgradeStone5", false);//this->gameSave.data.upgradeStone5 = false;
			this->setValue("upgradeLevin1", false);//this->gameSave.data.upgradeLevin1 = false;
			this->setValue("upgradeLevin2", false);//this->gameSave.data.upgradeLevin2 = false;
			this->setValue("upgradeLevin3", false);//this->gameSave.data.upgradeLevin3 = false;
			this->setValue("upgradeLevin4", false);//this->gameSave.data.upgradeLevin4 = false;
			this->setValue("upgradeLevin5", false);//this->gameSave.data.upgradeLevin5 = false;
			this->setValue("achieve_firstKill", false);//this->gameSave.data.achieve_firstKill = false;
			this->setValue("achieve_kill_100_enemies", false);//this->gameSave.data.achieve_kill_100_enemies = false;
			this->setValue("achieve_kill_2500_enemies", false);//this->gameSave.data.achieve_kill_2500_enemies = false;
			this->setValue("achieve_call_100_earlyWaves", false);//this->gameSave.data.achieve_call_100_earlyWaves = false;
			this->setValue("achieve_build_100_towers", false);//this->gameSave.data.achieve_build_100_towers = false;
			this->setValue("achieve_createGolem_5_times", false);//this->gameSave.data.achieve_createGolem_5_times = false;
			this->setValue("achieve_createIceman_15_times", false);//this->gameSave.data.achieve_createIceman_15_times = false;
			this->setValue("achieve_createAir_7_times", false);//this->gameSave.data.achieve_createAir_7_times = false;
			this->setValue("achieve_callAllWavesInLevel", false);//this->gameSave.data.achieve_callAllWavesInLevel = false;
			this->setValue("achieve_sellFireIceStoneLevin", false);//this->gameSave.data.achieve_sellFireIceStoneLevin = false;
			this->setValue("achieve_sellFire_10_times", false);//this->gameSave.data.achieve_sellFire_10_times = false;
			this->setValue("achieve_sellIce_10_times", false);//this->gameSave.data.achieve_sellIce_10_times = false;
			this->setValue("achieve_sellStone_10_times", false);//this->gameSave.data.achieve_sellStone_10_times = false;
			this->setValue("achieve_sellLevin_10_times", false);//this->gameSave.data.achieve_sellLevin_10_times = false;
			this->setValue("achieve_golemKill_250_enemies", false);//this->gameSave.data.achieve_golemKill_250_enemies = false;
			this->setValue("achieve_icemanSlowdown_75_enemies", false);//this->gameSave.data.achieve_icemanSlowdown_75_enemies = false;
			this->setValue("achieve_icemanSlowdown_500_enemies", false);//this->gameSave.data.achieve_icemanSlowdown_500_enemies = false;
			this->setValue("achieve_buildUltraTower", false);//this->gameSave.data.achieve_buildUltraTower = false;
			this->setValue("achieve_buildUltraTower_50_times", false);//this->gameSave.data.achieve_buildUltraTower_50_times = false;
			this->setValue("achieve_buildAllUltraTowers", false);//this->gameSave.data.achieve_buildAllUltraTowers = false;
			this->setValue("achieve_notCast", false);//this->gameSave.data.achieve_notCast = false;
			this->setValue("achieve_castFire_150_times", false);//this->gameSave.data.achieve_castFire_150_times = false;
			this->setValue("achieve_castIce_150_times", false);//this->gameSave.data.achieve_castIce_150_times = false;
			this->setValue("achieve_castStone_150_times", false);//this->gameSave.data.achieve_castStone_150_times = false;
			this->setValue("achieve_castLevin_150_times", false);//this->gameSave.data.achieve_castLevin_150_times = false;
			this->setValue("achieve_castGetAll_10_times", false);//this->gameSave.data.achieve_castGetAll_10_times = false;
			this->setValue("achieve_castGetAll_100_times", false);//this->gameSave.data.achieve_castGetAll_100_times = false;
			this->setValue("achieve_castKill_1_enemy", false);//this->gameSave.data.achieve_castKill_1_enemy = false;
			this->setValue("achieve_castKill_100_enemy", false);//this->gameSave.data.achieve_castKill_100_enemy = false;
			this->setValue("achieve_complete_10_hardLevels", false);//this->gameSave.data.achieve_complete_10_hardLevels = false;
			this->setValue("achieve_complete_10_survivalLevels", false);//this->gameSave.data.achieve_complete_10_survivalLevels = false;
			this->setValue("achieve_complete_10_withAllLives", false);//this->gameSave.data.achieve_complete_10_withAllLives = false;
			this->setValue("achieve_dude_01", false);//this->gameSave.data.achieve_dude_01 = false;
			this->setValue("achieve_dude_02", false);//this->gameSave.data.achieve_dude_02 = false;
			this->setValue("achieve_dude_03", false);//this->gameSave.data.achieve_dude_03 = false;
			this->setValue("achieve_dude_04", false);//this->gameSave.data.achieve_dude_04 = false;
			this->setValue("achieve_dude_05", false);//this->gameSave.data.achieve_dude_05 = false;
			this->setValue("achieve_dude_06", false);//this->gameSave.data.achieve_dude_06 = false;
			this->setValue("achieve_dude_07", false);//this->gameSave.data.achieve_dude_07 = false;
			this->setValue("achieve_dude_08", false);//this->gameSave.data.achieve_dude_08 = false;
			this->setValue("achieve_dude_09", false);//this->gameSave.data.achieve_dude_09 = false;
			this->setValue("achieve_dude_10", false);//this->gameSave.data.achieve_dude_10 = false;
			this->setValue("achieve_dude_11", false);//this->gameSave.data.achieve_dude_11 = false;
			this->setValue("achieve_dude_12", false);//this->gameSave.data.achieve_dude_12 = false;
			this->setValue("achieve_dude_13", false);//this->gameSave.data.achieve_dude_13 = false;
			this->setValue("achieve_dude_14", false);//this->gameSave.data.achieve_dude_14 = false;
			this->setValue("addit_killEnemiesCounter", 0);//this->gameSave.data.addit_killEnemiesCounter = 0;
			this->setValue("addit_earlyWavesCounter", 0);//this->gameSave.data.addit_earlyWavesCounter = 0;
			this->setValue("addit_buildTowerCounter", 0);//this->gameSave.data.addit_buildTowerCounter = 0;
			this->setValue("addit_golemCounter", 0);//this->gameSave.data.addit_golemCounter = 0;
			this->setValue("addit_icemanCounter", 0);//this->gameSave.data.addit_icemanCounter = 0;
			this->setValue("addit_airCounter", 0);//this->gameSave.data.addit_airCounter = 0;
			this->setValue("addit_sellFireCounter", 0);//this->gameSave.data.addit_sellFireCounter = 0;
			this->setValue("addit_sellIceCounter", 0);//this->gameSave.data.addit_sellIceCounter = 0;
			this->setValue("addit_sellStoneCounter", 0);//this->gameSave.data.addit_sellStoneCounter = 0;
			this->setValue("addit_sellLevinCounter", 0);//this->gameSave.data.addit_sellLevinCounter = 0;
			this->setValue("addit_golemKillEnemiesCounter", 0);//this->gameSave.data.addit_golemKillEnemiesCounter = 0;
			this->setValue("addit_icemanSlowdownEnemiesCounter", 0);//this->gameSave.data.addit_icemanSlowdownEnemiesCounter = 0;
			this->setValue("addit_buildUltraTowersCounter", 0);//this->gameSave.data.addit_buildUltraTowersCounter = 0;
			this->setValue("addit_castFireCounter", 0);//this->gameSave.data.addit_castFireCounter = 0;
			this->setValue("addit_castIceCounter", 0);//this->gameSave.data.addit_castIceCounter = 0;
			this->setValue("addit_castStoneCounter", 0);//this->gameSave.data.addit_castStoneCounter = 0;
			this->setValue("addit_castLevinCounter", 0);//this->gameSave.data.addit_castLevinCounter = 0;
			this->setValue("addit_castGetAllCounter", 0);//this->gameSave.data.addit_castGetAllCounter = 0;
			this->setValue("addit_castKillEnemiesCounter", 0);//this->gameSave.data.addit_castKillEnemiesCounter = 0;
			this->setValue("addit_completeEasyLevelsCounter", 0);//this->gameSave.data.addit_completeEasyLevelsCounter = 0;
			this->setValue("addit_completeNormalLevelsCounter", 0);//this->gameSave.data.addit_completeNormalLevelsCounter = 0;
			this->setValue("addit_completeHardLevelsCounter", 0);//this->gameSave.data.addit_completeHardLevelsCounter = 0;
			this->setValue("addit_completeSurvivalLevelsCounter", 0);//this->gameSave.data.addit_completeSurvivalLevelsCounter = 0;
			this->setValue("addit_completeLevelsWithAllLivesCounter", 0);//this->gameSave.data.addit_completeLevelsWithAllLivesCounter = 0;

			for(size_t i = 0; i < 15; i++)
				this->setValue("addit_levelsDefeatCounter", i, 0);
			//this->gameSave.data.addit_levelsDefeatCounter = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
			this->setValue("training_9", 0);//this->gameSave.data.training_9 = 0;
			this->setValue("training_91", 0);//this->gameSave.data.training_91 = 0;
			this->setValue("eduSurvHint", false);//this->gameSave.data.eduSurvHint = false;
			this->setValue("newLevel", 1);//this->gameSave.data.newLevel = 1;
			this->updateSever();
		}
		else if(!this->getBoolValue("addit_levelsDefeatCounter"))
			//else if (!Main::mainClass->saveBoxClass->getBoolValue("addit_levelsDefeatCounter"))
		{
			for(size_t i = 0; i < 15; i++)
				this->setValue("addit_levelsDefeatCounter", i, 0);
			//Main::mainClass->saveBoxClass->setValue("addit_levelsDefeatCounter") = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
		}
		//return;
	};

	void SaveBox::updateSever()
	{
		if (this->gameSave)
		{
			string saveIndex=this->getStringValue("saveIndex");
			if (saveIndex == "")return;
			if (this->getStringValue("type") != "site") {
				string wrPath=FileUtils::getInstance()->getWritablePath();
				string saveFile = wrPath + "/brave" + saveIndex + ".json";
				JsonUtil::writeFile(this->gameSave, saveFile);
				//// 3. 把 DOM 转换（stringify）成 JSON。
				//JsonUtil::StringBuffer buffer;
				//JsonUtil::Writer<JsonUtil::StringBuffer> writer(buffer);
				//this->gameSave->Accept(writer);
				//FileUtils::getInstance()->writeStringToFile(buffer.GetString(), saveFile);
			}else {
				//if (this->gameSave.data.saveNo == this->gameSave4.data.saveNo)
				//{
				//	this->siteSaveConvertionToServer(4);
				//	if (Main.mainClass.IDIClass.idnet)
				//	{
				//		Main.mainClass.IDIClass.saveData(4);
				//	}
				//}
				//else if (this->gameSave.data.saveNo == this->gameSave5.data.saveNo)
				//{
				//	this->siteSaveConvertionToServer(5);
				//	if (Main.mainClass.IDIClass.idnet)
				//	{
				//		Main.mainClass.IDIClass.saveData(5);
				//	}
				//}
				//else if (this->gameSave.data.saveNo == this->gameSave6.data.saveNo)
				//{
				//	this->siteSaveConvertionToServer(6);
				//	if (Main.mainClass.IDIClass.idnet)
				//	{
				//		Main.mainClass.IDIClass.saveData(6);
				//	}
				//}
			}
		}
		//return;
	};

	void SaveBox::siteSaveConvertionToLocal(int param1)
	{
		//this->tempObject = null;
		//tempObjec1 = null;
		//if (param1 == 4)
		//{
		//	this->tempObject = Main.mainClass.IDIClass.gameSave1;
		//	this->tempObject1 = this->gameSave4;
		//}
		//else if (param1 == 5)
		//{
		//	this->tempObject = Main.mainClass.IDIClass.gameSave2;
		//	this->tempObject1 = this->gameSave5;
		//}
		//else if (param1 == 6)
		//{
		//	this->tempObject = Main.mainClass.IDIClass.gameSave3;
		//	this->tempObject1 = this->gameSave6;
		//}
		//if (this->tempObject)
		//{
		//	this->tempObject1.data.haveSave = this->tempObject["haveSave"];
		//	this->tempObject1.data.stars = this->tempObject["stars"];
		//	this->tempObject1.data.openLevels = this->tempObject["openLevels"];
		//	this->tempObject1.data.starsOfLevels = this->tempObject["starsOfLevels"];
		//	this->tempObject1.data.levelsFinish = this->tempObject["levelsFinish"];
		//	this->tempObject1.data.quality = this->tempObject["quality"];
		//	this->tempObject1.data.autoPause = this->tempObject["autoPause"];
		//	this->tempObject1.data.firstViewEnemies = this->tempObject["firstViewEnemies"];
		//	this->tempObject1.data.firstViewTowers = this->tempObject["firstViewTowers"];
		//	this->tempObject1.data.complexityLevel = this->tempObject["complexityLevel"];
		//	this->tempObject1.data.oldComplexityLevel = this->tempObject["oldComplexityLevel"];
		//	this->tempObject1.data.newLevel = this->tempObject["newLevel"];
		//	this->tempObject1.data.newStarsForLevel = this->tempObject["newStarsForLevel"];
		//	this->tempObject1.data.difficultyLevel = this->tempObject["difficultyLevel"];
		//	this->tempObject1.data.saveNo = this->tempObject["saveNo"];
		//	this->tempObject1.data.type = this->tempObject["type"];
		//	this->tempObject1.data.upgradeGolem1 = this->tempObject["upgradeGolem1"];
		//	this->tempObject1.data.upgradeGolem2 = this->tempObject["upgradeGolem2"];
		//	this->tempObject1.data.upgradeGolem3 = this->tempObject["upgradeGolem3"];
		//	this->tempObject1.data.upgradeGolem4 = this->tempObject["upgradeGolem4"];
		//	this->tempObject1.data.upgradeGolem5 = this->tempObject["upgradeGolem5"];
		//	this->tempObject1.data.upgradeIceman1 = this->tempObject["upgradeIceman1"];
		//	this->tempObject1.data.upgradeIceman2 = this->tempObject["upgradeIceman2"];
		//	this->tempObject1.data.upgradeIceman3 = this->tempObject["upgradeIceman3"];
		//	this->tempObject1.data.upgradeIceman4 = this->tempObject["upgradeIceman4"];
		//	this->tempObject1.data.upgradeIceman5 = this->tempObject["upgradeIceman5"];
		//	this->tempObject1.data.upgradeAir1 = this->tempObject["upgradeAir1"];
		//	this->tempObject1.data.upgradeAir2 = this->tempObject["upgradeAir2"];
		//	this->tempObject1.data.upgradeAir3 = this->tempObject["upgradeAir3"];
		//	this->tempObject1.data.upgradeAir4 = this->tempObject["upgradeAir4"];
		//	this->tempObject1.data.upgradeAir5 = this->tempObject["upgradeAir5"];
		//	this->tempObject1.data.upgradeFire1 = this->tempObject["upgradeFire1"];
		//	this->tempObject1.data.upgradeFire2 = this->tempObject["upgradeFire2"];
		//	this->tempObject1.data.upgradeFire3 = this->tempObject["upgradeFire3"];
		//	this->tempObject1.data.upgradeFire4 = this->tempObject["upgradeFire4"];
		//	this->tempObject1.data.upgradeFire5 = this->tempObject["upgradeFire5"];
		//	this->tempObject1.data.upgradeIce1 = this->tempObject["upgradeIce1"];
		//	this->tempObject1.data.upgradeIce2 = this->tempObject["upgradeIce2"];
		//	this->tempObject1.data.upgradeIce3 = this->tempObject["upgradeIce3"];
		//	this->tempObject1.data.upgradeIce4 = this->tempObject["upgradeIce4"];
		//	this->tempObject1.data.upgradeIce5 = this->tempObject["upgradeIce5"];
		//	this->tempObject1.data.upgradeStone1 = this->tempObject["upgradeStone1"];
		//	this->tempObject1.data.upgradeStone2 = this->tempObject["upgradeStone2"];
		//	this->tempObject1.data.upgradeStone3 = this->tempObject["upgradeStone3"];
		//	this->tempObject1.data.upgradeStone4 = this->tempObject["upgradeStone4"];
		//	this->tempObject1.data.upgradeStone5 = this->tempObject["upgradeStone5"];
		//	this->tempObject1.data.upgradeLevin1 = this->tempObject["upgradeLevin1"];
		//	this->tempObject1.data.upgradeLevin2 = this->tempObject["upgradeLevin2"];
		//	this->tempObject1.data.upgradeLevin3 = this->tempObject["upgradeLevin3"];
		//	this->tempObject1.data.upgradeLevin4 = this->tempObject["upgradeLevin4"];
		//	this->tempObject1.data.upgradeLevin5 = this->tempObject["upgradeLevin5"];
		//	this->tempObject1.data.achieve_firstKill = this->tempObject["achieve_firstKill"];
		//	this->tempObject1.data.achieve_kill_100_enemies = this->tempObject["achieve_kill_100_enemies"];
		//	this->tempObject1.data.achieve_kill_2500_enemies = this->tempObject["achieve_kill_2500_enemies"];
		//	this->tempObject1.data.achieve_call_100_earlyWaves = this->tempObject["achieve_call_100_earlyWaves"];
		//	this->tempObject1.data.achieve_build_100_towers = this->tempObject["achieve_build_100_towers"];
		//	this->tempObject1.data.achieve_createGolem_5_times = this->tempObject["achieve_createGolem_5_times"];
		//	this->tempObject1.data.achieve_createIceman_15_times = this->tempObject["achieve_createIceman_15_times"];
		//	this->tempObject1.data.achieve_createAir_7_times = this->tempObject["achieve_createAir_7_times"];
		//	this->tempObject1.data.achieve_callAllWavesInLevel = this->tempObject["achieve_callAllWavesInLevel"];
		//	this->tempObject1.data.achieve_sellFireIceStoneLevin = this->tempObject["achieve_sellFireIceStoneLevin"];
		//	this->tempObject1.data.achieve_sellFire_10_times = this->tempObject["achieve_sellFire_10_times"];
		//	this->tempObject1.data.achieve_sellIce_10_times = this->tempObject["achieve_sellIce_10_times"];
		//	this->tempObject1.data.achieve_sellStone_10_times = this->tempObject["achieve_sellStone_10_times"];
		//	this->tempObject1.data.achieve_sellLevin_10_times = this->tempObject["achieve_sellLevin_10_times"];
		//	this->tempObject1.data.achieve_golemKill_250_enemies = this->tempObject["achieve_golemKill_250_enemies"];
		//	this->tempObject1.data.achieve_icemanSlowdown_75_enemies = this->tempObject["achieve_icemanSlowdown_75_enemies"];
		//	this->tempObject1.data.achieve_icemanSlowdown_500_enemies = this->tempObject["achieve_icemanSlowdown_500_enemies"];
		//	this->tempObject1.data.achieve_buildUltraTower = this->tempObject["achieve_buildUltraTower"];
		//	this->tempObject1.data.achieve_buildUltraTower_50_times = this->tempObject["achieve_buildUltraTower_50_times"];
		//	this->tempObject1.data.achieve_buildAllUltraTowers = this->tempObject["achieve_buildAllUltraTowers"];
		//	this->tempObject1.data.achieve_notCast = this->tempObject["achieve_notCast"];
		//	this->tempObject1.data.achieve_castFire_150_times = this->tempObject["achieve_castFire_150_times"];
		//	this->tempObject1.data.achieve_castIce_150_times = this->tempObject["achieve_castIce_150_times"];
		//	this->tempObject1.data.achieve_castStone_150_times = this->tempObject["achieve_castStone_150_times"];
		//	this->tempObject1.data.achieve_castLevin_150_times = this->tempObject["achieve_castLevin_150_times"];
		//	this->tempObject1.data.achieve_castGetAll_10_times = this->tempObject["achieve_castGetAll_10_times"];
		//	this->tempObject1.data.achieve_castGetAll_100_times = this->tempObject["achieve_castGetAll_100_times"];
		//	this->tempObject1.data.achieve_castKill_1_enemy = this->tempObject["achieve_castKill_1_enemy"];
		//	this->tempObject1.data.achieve_castKill_100_enemy = this->tempObject["achieve_castKill_100_enemy"];
		//	this->tempObject1.data.achieve_complete_10_hardLevels = this->tempObject["achieve_complete_10_hardLevels"];
		//	this->tempObject1.data.achieve_complete_10_survivalLevels = this->tempObject["achieve_complete_10_survivalLevels"];
		//	this->tempObject1.data.achieve_complete_10_withAllLives = this->tempObject["achieve_complete_10_withAllLives"];
		//	this->tempObject1.data.achieve_dude_01 = this->tempObject["achieve_dude_01"];
		//	this->tempObject1.data.achieve_dude_02 = this->tempObject["achieve_dude_02"];
		//	this->tempObject1.data.achieve_dude_03 = this->tempObject["achieve_dude_03"];
		//	this->tempObject1.data.achieve_dude_04 = this->tempObject["achieve_dude_04"];
		//	this->tempObject1.data.achieve_dude_05 = this->tempObject["achieve_dude_05"];
		//	this->tempObject1.data.achieve_dude_06 = this->tempObject["achieve_dude_06"];
		//	this->tempObject1.data.achieve_dude_07 = this->tempObject["achieve_dude_07"];
		//	this->tempObject1.data.achieve_dude_08 = this->tempObject["achieve_dude_08"];
		//	this->tempObject1.data.achieve_dude_09 = this->tempObject["achieve_dude_09"];
		//	this->tempObject1.data.achieve_dude_10 = this->tempObject["achieve_dude_10"];
		//	this->tempObject1.data.achieve_dude_11 = this->tempObject["achieve_dude_11"];
		//	this->tempObject1.data.achieve_dude_12 = this->tempObject["achieve_dude_12"];
		//	this->tempObject1.data.achieve_dude_13 = this->tempObject["achieve_dude_13"];
		//	this->tempObject1.data.achieve_dude_14 = this->tempObject["achieve_dude_14"];
		//	this->tempObject1.data.addit_killEnemiesCounter = this->tempObject["addit_killEnemiesCounter"];
		//	this->tempObject1.data.addit_earlyWavesCounter = this->tempObject["addit_earlyWavesCounter"];
		//	this->tempObject1.data.addit_buildTowerCounter = this->tempObject["addit_buildTowerCounter"];
		//	this->tempObject1.data.addit_golemCounter = this->tempObject["addit_golemCounter"];
		//	this->tempObject1.data.addit_icemanCounter = this->tempObject["addit_icemanCounter"];
		//	this->tempObject1.data.addit_airCounter = this->tempObject["addit_airCounter"];
		//	this->tempObject1.data.addit_sellFireCounter = this->tempObject["addit_sellFireCounter"];
		//	this->tempObject1.data.addit_sellIceCounter = this->tempObject["addit_sellIceCounter"];
		//	this->tempObject1.data.addit_sellStoneCounter = this->tempObject["addit_sellStoneCounter"];
		//	this->tempObject1.data.addit_sellLevinCounter = this->tempObject["addit_sellLevinCounter"];
		//	this->tempObject1.data.addit_golemKillEnemiesCounter = this->tempObject["addit_golemKillEnemiesCounter"];
		//	this->tempObject1.data.addit_icemanSlowdownEnemiesCounter = this->tempObject["addit_icemanSlowdownEnemiesCounter"];
		//	this->tempObject1.data.addit_buildUltraTowersCounter = this->tempObject["addit_buildUltraTowersCounter"];
		//	this->tempObject1.data.addit_castFireCounter = this->tempObject["addit_castFireCounter"];
		//	this->tempObject1.data.addit_castIceCounter = this->tempObject["addit_castIceCounter"];
		//	this->tempObject1.data.addit_castStoneCounter = this->tempObject["addit_castStoneCounter"];
		//	this->tempObject1.data.addit_castLevinCounter = this->tempObject["addit_castLevinCounter"];
		//	this->tempObject1.data.addit_castGetAllCounter = this->tempObject["addit_castGetAllCounter"];
		//	this->tempObject1.data.addit_castKillEnemiesCounter = this->tempObject["addit_castKillEnemiesCounter"];
		//	this->tempObject1.data.addit_completeEasyLevelsCounter = this->tempObject["addit_completeEasyLevelsCounter"];
		//	this->tempObject1.data.addit_completeNormalLevelsCounter = this->tempObject["addit_completeNormalLevelsCounter"];
		//	this->tempObject1.data.addit_completeHardLevelsCounter = this->tempObject["addit_completeHardLevelsCounter"];
		//	this->tempObject1.data.addit_completeSurvivalLevelsCounter = this->tempObject["addit_completeSurvivalLevelsCounter"];
		//	this->tempObject1.data.addit_completeLevelsWithAllLivesCounter = this->tempObject["addit_completeLevelsWithAllLivesCounter"];
		//	this->tempObject1.data.addit_levelsDefeatCounter = this->tempObject["addit_levelsDefeatCounter"];
		//	this->tempObject1.data.training_9 = this->tempObject["training_9"];
		//	this->tempObject1.data.training_91 = this->tempObject["training_91"];
		//	this->tempObject1.data.eduSurvHint = this->tempObject["eduSurvHint"];
		//	if (param1 == 4)
		//	{
		//		this->gameSave4 = this->tempObject1;
		//	}
		//	else if (param1 == 5)
		//	{
		//		this->gameSave5 = this->tempObject1;
		//	}
		//	else if (param1 == 6)
		//	{
		//		this->gameSave6 = this->tempObject1;
		//	}
		//}
		//return;
	};

	void SaveBox::siteSaveConvertionToServer(int param1)
	{
		//if (param1 == 4)
		//{
		//	this->tempObject1 = this->gameSave4;
		//}
		//else if (param1 == 5)
		//{
		//	this->tempObject1 = this->gameSave5;
		//}
		//else if (param1 == 6)
		//{
		//	this->tempObject1 = this->gameSave6;
		//}
		//if (this->tempObject1.data.haveSave)
		//{
		//	this->tempObject = { haveSave:this->tempObject1.data.haveSave, stars : this->tempObject1.data.stars, openLevels : this->tempObject1.data.openLevels, starsOfLevels : this->tempObject1.data.starsOfLevels, levelsFinish : this->tempObject1.data.levelsFinish, quality : this->tempObject1.data.quality, autoPause : this->tempObject1.data.autoPause, firstViewEnemies : this->tempObject1.data.firstViewEnemies, firstViewTowers : this->tempObject1.data.firstViewTowers, complexityLevel : this->tempObject1.data.complexityLevel, oldComplexityLevel : this->tempObject1.data.oldComplexityLevel, newLevel : this->tempObject1.data.newLevel, newStarsForLevel : this->tempObject1.data.newStarsForLevel, difficultyLevel : this->tempObject1.data.difficultyLevel, saveNo : this->tempObject1.data.saveNo, type : this->tempObject1.data.type, upgradeGolem1 : this->tempObject1.data.upgradeGolem1, upgradeGolem2 : this->tempObject1.data.upgradeGolem2, upgradeGolem3 : this->tempObject1.data.upgradeGolem3, upgradeGolem4 : this->tempObject1.data.upgradeGolem4, upgradeGolem5 : this->tempObject1.data.upgradeGolem5, upgradeIceman1 : this->tempObject1.data.upgradeIceman1, upgradeIceman2 : this->tempObject1.data.upgradeIceman2, upgradeIceman3 : this->tempObject1.data.upgradeIceman3, upgradeIceman4 : this->tempObject1.data.upgradeIceman4, upgradeIceman5 : this->tempObject1.data.upgradeIceman5, upgradeAir1 : this->tempObject1.data.upgradeAir1, upgradeAir2 : this->tempObject1.data.upgradeAir2, upgradeAir3 : this->tempObject1.data.upgradeAir3, upgradeAir4 : this->tempObject1.data.upgradeAir4, upgradeAir5 : this->tempObject1.data.upgradeAir5, upgradeFire1 : this->tempObject1.data.upgradeFire1, upgradeFire2 : this->tempObject1.data.upgradeFire2, upgradeFire3 : this->tempObject1.data.upgradeFire3, upgradeFire4 : this->tempObject1.data.upgradeFire4, upgradeFire5 : this->tempObject1.data.upgradeFire5, upgradeIce1 : this->tempObject1.data.upgradeIce1, upgradeIce2 : this->tempObject1.data.upgradeIce2, upgradeIce3 : this->tempObject1.data.upgradeIce3, upgradeIce4 : this->tempObject1.data.upgradeIce4, upgradeIce5 : this->tempObject1.data.upgradeIce5, upgradeStone1 : this->tempObject1.data.upgradeStone1, upgradeStone2 : this->tempObject1.data.upgradeStone2, upgradeStone3 : this->tempObject1.data.upgradeStone3, upgradeStone4 : this->tempObject1.data.upgradeStone4, upgradeStone5 : this->tempObject1.data.upgradeStone5, upgradeLevin1 : this->tempObject1.data.upgradeLevin1, upgradeLevin2 : this->tempObject1.data.upgradeLevin2, upgradeLevin3 : this->tempObject1.data.upgradeLevin3, upgradeLevin4 : this->tempObject1.data.upgradeLevin4, upgradeLevin5 : this->tempObject1.data.upgradeLevin5, achieve_firstKill : this->tempObject1.data.achieve_firstKill, achieve_kill_100_enemies : this->tempObject1.data.achieve_kill_100_enemies, achieve_kill_2500_enemies : this->tempObject1.data.achieve_kill_2500_enemies, achieve_call_100_earlyWaves : this->tempObject1.data.achieve_call_100_earlyWaves, achieve_build_100_towers : this->tempObject1.data.achieve_build_100_towers, achieve_createGolem_5_times : this->tempObject1.data.achieve_createGolem_5_times, achieve_createIceman_15_times : this->tempObject1.data.achieve_createIceman_15_times, achieve_createAir_7_times : this->tempObject1.data.achieve_createAir_7_times, achieve_callAllWavesInLevel : this->tempObject1.data.achieve_callAllWavesInLevel, achieve_sellFireIceStoneLevin : this->tempObject1.data.achieve_sellFireIceStoneLevin, achieve_sellFire_10_times : this->tempObject1.data.achieve_sellFire_10_times, achieve_sellIce_10_times : this->tempObject1.data.achieve_sellIce_10_times, achieve_sellStone_10_times : this->tempObject1.data.achieve_sellStone_10_times, achieve_sellLevin_10_times : this->tempObject1.data.achieve_sellLevin_10_times, achieve_golemKill_250_enemies : this->tempObject1.data.achieve_golemKill_250_enemies, achieve_icemanSlowdown_75_enemies : this->tempObject1.data.achieve_icemanSlowdown_75_enemies, achieve_icemanSlowdown_500_enemies : this->tempObject1.data.achieve_icemanSlowdown_500_enemies, achieve_buildUltraTower : this->tempObject1.data.achieve_buildUltraTower, achieve_buildUltraTower_50_times : this->tempObject1.data.achieve_buildUltraTower_50_times, achieve_buildAllUltraTowers : this->tempObject1.data.achieve_buildAllUltraTowers, achieve_notCast : this->tempObject1.data.achieve_notCast, achieve_castFire_150_times : this->tempObject1.data.achieve_castFire_150_times, achieve_castIce_150_times : this->tempObject1.data.achieve_castIce_150_times, achieve_castStone_150_times : this->tempObject1.data.achieve_castStone_150_times, achieve_castLevin_150_times : this->tempObject1.data.achieve_castLevin_150_times, achieve_castGetAll_10_times : this->tempObject1.data.achieve_castGetAll_10_times, achieve_castGetAll_100_times : this->tempObject1.data.achieve_castGetAll_100_times, achieve_castKill_1_enemy : this->tempObject1.data.achieve_castKill_1_enemy, achieve_castKill_100_enemy : this->tempObject1.data.achieve_castKill_100_enemy, achieve_complete_10_hardLevels : this->tempObject1.data.achieve_complete_10_hardLevels, achieve_complete_10_survivalLevels : this->tempObject1.data.achieve_complete_10_survivalLevels, achieve_complete_10_withAllLives : this->tempObject1.data.achieve_complete_10_withAllLives, achieve_dude_01 : this->tempObject1.data.achieve_dude_01, achieve_dude_02 : this->tempObject1.data.achieve_dude_02, achieve_dude_03 : this->tempObject1.data.achieve_dude_03, achieve_dude_04 : this->tempObject1.data.achieve_dude_04, achieve_dude_05 : this->tempObject1.data.achieve_dude_05, achieve_dude_06 : this->tempObject1.data.achieve_dude_06, achieve_dude_07 : this->tempObject1.data.achieve_dude_07, achieve_dude_08 : this->tempObject1.data.achieve_dude_08, achieve_dude_09 : this->tempObject1.data.achieve_dude_09, achieve_dude_10 : this->tempObject1.data.achieve_dude_10, achieve_dude_11 : this->tempObject1.data.achieve_dude_11, achieve_dude_12 : this->tempObject1.data.achieve_dude_12, achieve_dude_13 : this->tempObject1.data.achieve_dude_13, achieve_dude_14 : this->tempObject1.data.achieve_dude_14, addit_killEnemiesCounter : this->tempObject1.data.addit_killEnemiesCounter, addit_earlyWavesCounter : this->tempObject1.data.addit_earlyWavesCounter, addit_buildTowerCounter : this->tempObject1.data.addit_buildTowerCounter, addit_golemCounter : this->tempObject1.data.addit_golemCounter, addit_icemanCounter : this->tempObject1.data.addit_icemanCounter, addit_airCounter : this->tempObject1.data.addit_airCounter, addit_sellFireCounter : this->tempObject1.data.addit_sellFireCounter, addit_sellIceCounter : this->tempObject1.data.addit_sellIceCounter, addit_sellStoneCounter : this->tempObject1.data.addit_sellStoneCounter, addit_sellLevinCounter : this->tempObject1.data.addit_sellLevinCounter, addit_golemKillEnemiesCounter : this->tempObject1.data.addit_golemKillEnemiesCounter, addit_icemanSlowdownEnemiesCounter : this->tempObject1.data.addit_icemanSlowdownEnemiesCounter, addit_buildUltraTowersCounter : this->tempObject1.data.addit_buildUltraTowersCounter, addit_castFireCounter : this->tempObject1.data.addit_castFireCounter, addit_castIceCounter : this->tempObject1.data.addit_castIceCounter, addit_castStoneCounter : this->tempObject1.data.addit_castStoneCounter, addit_castLevinCounter : this->tempObject1.data.addit_castLevinCounter, addit_castGetAllCounter : this->tempObject1.data.addit_castGetAllCounter, addit_castKillEnemiesCounter : this->tempObject1.data.addit_castKillEnemiesCounter, addit_completeEasyLevelsCounter : this->tempObject1.data.addit_completeEasyLevelsCounter, addit_completeNormalLevelsCounter : this->tempObject1.data.addit_completeNormalLevelsCounter, addit_completeHardLevelsCounter : this->tempObject1.data.addit_completeHardLevelsCounter, addit_completeSurvivalLevelsCounter : this->tempObject1.data.addit_completeSurvivalLevelsCounter, addit_completeLevelsWithAllLivesCounter : this->tempObject1.data.addit_completeLevelsWithAllLivesCounter, addit_levelsDefeatCounter : this->tempObject1.data.addit_levelsDefeatCounter, training_9 : this->tempObject1.data.training_9, training_91 : this->tempObject1.data.training_91, eduSurvHint : this->tempObject1.data.eduSurvHint };
		//	if (param1 == 4)
		//	{
		//		Main.mainClass.IDIClass.gameSave1 = this->tempObject;
		//	}
		//	else if (param1 == 5)
		//	{
		//		Main.mainClass.IDIClass.gameSave2 = this->tempObject;
		//	}
		//	else if (param1 == 6)
		//	{
		//		Main.mainClass.IDIClass.gameSave3 = this->tempObject;
		//	}
		//}
		//return;
	};

	void SaveBox::synchronizationLocalToSite(int param1)
	{
		//if (param1 == 1)
		//{
		//	this->tempObject = this->gameSave1;
		//	this->tempObject1 = this->gameSave4;
		//}
		//else if (param1 == 2)
		//{
		//	this->tempObject = this->gameSave2;
		//	this->tempObject1 = this->gameSave5;
		//}
		//else if (param1 == 3)
		//{
		//	this->tempObject = this->gameSave3;
		//	this->tempObject1 = this->gameSave6;
		//}
		//this->tempObject1.data.haveSave = true;
		//this->tempObject1.data.openLevels = [];
		//this->tempObject1.data.openLevels[0] = this->tempObject.data.openLevels[0];
		//this->tempObject1.data.openLevels[1] = this->tempObject.data.openLevels[1];
		//this->tempObject1.data.openLevels[2] = this->tempObject.data.openLevels[2];
		//this->tempObject1.data.openLevels[3] = this->tempObject.data.openLevels[3];
		//this->tempObject1.data.openLevels[4] = this->tempObject.data.openLevels[4];
		//this->tempObject1.data.openLevels[5] = this->tempObject.data.openLevels[5];
		//this->tempObject1.data.openLevels[6] = this->tempObject.data.openLevels[6];
		//this->tempObject1.data.openLevels[7] = this->tempObject.data.openLevels[7];
		//this->tempObject1.data.openLevels[8] = this->tempObject.data.openLevels[8];
		//this->tempObject1.data.openLevels[9] = this->tempObject.data.openLevels[9];
		//this->tempObject1.data.openLevels[10] = this->tempObject.data.openLevels[10];
		//this->tempObject1.data.openLevels[11] = this->tempObject.data.openLevels[11];
		//this->tempObject1.data.openLevels[12] = this->tempObject.data.openLevels[12];
		//this->tempObject1.data.openLevels[13] = this->tempObject.data.openLevels[13];
		//this->tempObject1.data.openLevels[14] = this->tempObject.data.openLevels[14];
		//this->tempObject1.data.starsOfLevels = [];
		//this->tempObject1.data.starsOfLevels[0] = this->tempObject.data.starsOfLevels[0];
		//this->tempObject1.data.starsOfLevels[1] = this->tempObject.data.starsOfLevels[1];
		//this->tempObject1.data.starsOfLevels[2] = this->tempObject.data.starsOfLevels[2];
		//this->tempObject1.data.starsOfLevels[3] = this->tempObject.data.starsOfLevels[3];
		//this->tempObject1.data.starsOfLevels[4] = this->tempObject.data.starsOfLevels[4];
		//this->tempObject1.data.starsOfLevels[5] = this->tempObject.data.starsOfLevels[5];
		//this->tempObject1.data.starsOfLevels[6] = this->tempObject.data.starsOfLevels[6];
		//this->tempObject1.data.starsOfLevels[7] = this->tempObject.data.starsOfLevels[7];
		//this->tempObject1.data.starsOfLevels[8] = this->tempObject.data.starsOfLevels[8];
		//this->tempObject1.data.starsOfLevels[9] = this->tempObject.data.starsOfLevels[9];
		//this->tempObject1.data.starsOfLevels[10] = this->tempObject.data.starsOfLevels[10];
		//this->tempObject1.data.starsOfLevels[11] = this->tempObject.data.starsOfLevels[11];
		//this->tempObject1.data.starsOfLevels[12] = this->tempObject.data.starsOfLevels[12];
		//this->tempObject1.data.starsOfLevels[13] = this->tempObject.data.starsOfLevels[13];
		//this->tempObject1.data.starsOfLevels[14] = this->tempObject.data.starsOfLevels[14];
		//this->tempObject1.data.levelsFinish = [];
		//this->tempObject1.data.levelsFinish[0] = this->tempObject.data.levelsFinish[0];
		//this->tempObject1.data.levelsFinish[1] = this->tempObject.data.levelsFinish[1];
		//this->tempObject1.data.levelsFinish[2] = this->tempObject.data.levelsFinish[2];
		//this->tempObject1.data.levelsFinish[3] = this->tempObject.data.levelsFinish[3];
		//this->tempObject1.data.levelsFinish[4] = this->tempObject.data.levelsFinish[4];
		//this->tempObject1.data.levelsFinish[5] = this->tempObject.data.levelsFinish[5];
		//this->tempObject1.data.levelsFinish[6] = this->tempObject.data.levelsFinish[6];
		//this->tempObject1.data.levelsFinish[7] = this->tempObject.data.levelsFinish[7];
		//this->tempObject1.data.levelsFinish[8] = this->tempObject.data.levelsFinish[8];
		//this->tempObject1.data.levelsFinish[9] = this->tempObject.data.levelsFinish[9];
		//this->tempObject1.data.levelsFinish[10] = this->tempObject.data.levelsFinish[10];
		//this->tempObject1.data.levelsFinish[11] = this->tempObject.data.levelsFinish[11];
		//this->tempObject1.data.levelsFinish[12] = this->tempObject.data.levelsFinish[12];
		//this->tempObject1.data.levelsFinish[13] = this->tempObject.data.levelsFinish[13];
		//this->tempObject1.data.levelsFinish[14] = this->tempObject.data.levelsFinish[14];
		//this->tempObject1.data.quality = this->tempObject.data.quality;
		//this->tempObject1.data.autoPause = this->tempObject.data.autoPause;
		//this->tempObject1.data.firstViewEnemies = [];
		//this->tempObject1.data.firstViewEnemies[0] = this->tempObject.data.firstViewEnemies[0];
		//this->tempObject1.data.firstViewEnemies[1] = this->tempObject.data.firstViewEnemies[1];
		//this->tempObject1.data.firstViewEnemies[2] = this->tempObject.data.firstViewEnemies[2];
		//this->tempObject1.data.firstViewEnemies[3] = this->tempObject.data.firstViewEnemies[3];
		//this->tempObject1.data.firstViewEnemies[4] = this->tempObject.data.firstViewEnemies[4];
		//this->tempObject1.data.firstViewEnemies[5] = this->tempObject.data.firstViewEnemies[5];
		//this->tempObject1.data.firstViewEnemies[6] = this->tempObject.data.firstViewEnemies[6];
		//this->tempObject1.data.firstViewEnemies[7] = this->tempObject.data.firstViewEnemies[7];
		//this->tempObject1.data.firstViewEnemies[8] = this->tempObject.data.firstViewEnemies[8];
		//this->tempObject1.data.firstViewEnemies[9] = this->tempObject.data.firstViewEnemies[9];
		//this->tempObject1.data.firstViewEnemies[10] = this->tempObject.data.firstViewEnemies[10];
		//this->tempObject1.data.firstViewEnemies[11] = this->tempObject.data.firstViewEnemies[11];
		//this->tempObject1.data.firstViewEnemies[12] = this->tempObject.data.firstViewEnemies[12];
		//this->tempObject1.data.firstViewEnemies[13] = this->tempObject.data.firstViewEnemies[13];
		//this->tempObject1.data.firstViewEnemies[14] = this->tempObject.data.firstViewEnemies[14];
		//this->tempObject1.data.firstViewEnemies[15] = this->tempObject.data.firstViewEnemies[15];
		//this->tempObject1.data.firstViewEnemies[16] = this->tempObject.data.firstViewEnemies[16];
		//this->tempObject1.data.firstViewEnemies[17] = this->tempObject.data.firstViewEnemies[17];
		//this->tempObject1.data.firstViewEnemies[18] = this->tempObject.data.firstViewEnemies[18];
		//this->tempObject1.data.firstViewEnemies[19] = this->tempObject.data.firstViewEnemies[19];
		//this->tempObject1.data.firstViewEnemies[20] = this->tempObject.data.firstViewEnemies[20];
		//this->tempObject1.data.firstViewEnemies[21] = this->tempObject.data.firstViewEnemies[21];
		//this->tempObject1.data.firstViewEnemies[22] = this->tempObject.data.firstViewEnemies[22];
		//this->tempObject1.data.firstViewEnemies[23] = this->tempObject.data.firstViewEnemies[23];
		//this->tempObject1.data.firstViewEnemies[24] = this->tempObject.data.firstViewEnemies[24];
		//this->tempObject1.data.firstViewEnemies[25] = this->tempObject.data.firstViewEnemies[25];
		//this->tempObject1.data.firstViewEnemies[26] = this->tempObject.data.firstViewEnemies[26];
		//this->tempObject1.data.firstViewEnemies[27] = this->tempObject.data.firstViewEnemies[27];
		//this->tempObject1.data.firstViewEnemies[28] = this->tempObject.data.firstViewEnemies[28];
		//this->tempObject1.data.firstViewEnemies[29] = this->tempObject.data.firstViewEnemies[29];
		//this->tempObject1.data.firstViewEnemies[30] = this->tempObject.data.firstViewEnemies[30];
		//this->tempObject1.data.firstViewEnemies[31] = this->tempObject.data.firstViewEnemies[31];
		//this->tempObject1.data.firstViewEnemies[32] = this->tempObject.data.firstViewEnemies[32];
		//this->tempObject1.data.firstViewTowers = [];
		//this->tempObject1.data.firstViewTowers[0] = this->tempObject.data.firstViewTowers[0];
		//this->tempObject1.data.firstViewTowers[1] = this->tempObject.data.firstViewTowers[1];
		//this->tempObject1.data.firstViewTowers[2] = this->tempObject.data.firstViewTowers[2];
		//this->tempObject1.data.firstViewTowers[3] = this->tempObject.data.firstViewTowers[3];
		//this->tempObject1.data.firstViewTowers[4] = this->tempObject.data.firstViewTowers[4];
		//this->tempObject1.data.firstViewTowers[5] = this->tempObject.data.firstViewTowers[5];
		//this->tempObject1.data.firstViewTowers[6] = this->tempObject.data.firstViewTowers[6];
		//this->tempObject1.data.firstViewTowers[7] = this->tempObject.data.firstViewTowers[7];
		//this->tempObject1.data.complexityLevel = this->tempObject.data.complexityLevel;
		//this->tempObject1.data.oldComplexityLevel = this->tempObject.data.oldComplexityLevel;
		//this->tempObject1.data.newLevel = this->tempObject.data.newLevel;
		//this->tempObject1.data.newStarsForLevel = this->tempObject.data.newStarsForLevel;
		//this->tempObject1.data.difficultyLevel = this->tempObject.data.difficultyLevel;
		//if (param1 == 1)
		//{
		//	this->tempObject1.data.saveNo = 4;
		//}
		//else if (param1 == 2)
		//{
		//	this->tempObject1.data.saveNo = 5;
		//}
		//else if (param1 == 3)
		//{
		//	this->tempObject1.data.saveNo = 6;
		//}
		//this->tempObject1.data.type = "site";
		//this->tempObject1.data.stars = this->tempObject.data.stars + 3;
		//this->tempObject1.data.firstRC = this->tempObject.data.firstRC;
		//this->tempObject1.data.firstClickKeepAll = this->tempObject.data.firstClickKeepAll;
		//this->tempObject1.data.upgradeGolem1 = this->tempObject.data.upgradeGolem1;
		//this->tempObject1.data.upgradeGolem2 = this->tempObject.data.upgradeGolem2;
		//this->tempObject1.data.upgradeGolem3 = this->tempObject.data.upgradeGolem3;
		//this->tempObject1.data.upgradeGolem4 = this->tempObject.data.upgradeGolem4;
		//this->tempObject1.data.upgradeGolem5 = this->tempObject.data.upgradeGolem5;
		//this->tempObject1.data.upgradeIceman1 = this->tempObject.data.upgradeIceman1;
		//this->tempObject1.data.upgradeIceman2 = this->tempObject.data.upgradeIceman2;
		//this->tempObject1.data.upgradeIceman3 = this->tempObject.data.upgradeIceman3;
		//this->tempObject1.data.upgradeIceman4 = this->tempObject.data.upgradeIceman4;
		//this->tempObject1.data.upgradeIceman5 = this->tempObject.data.upgradeIceman5;
		//this->tempObject1.data.upgradeAir1 = this->tempObject.data.upgradeAir1;
		//this->tempObject1.data.upgradeAir2 = this->tempObject.data.upgradeAir2;
		//this->tempObject1.data.upgradeAir3 = this->tempObject.data.upgradeAir3;
		//this->tempObject1.data.upgradeAir4 = this->tempObject.data.upgradeAir4;
		//this->tempObject1.data.upgradeAir5 = this->tempObject.data.upgradeAir5;
		//this->tempObject1.data.upgradeFire1 = this->tempObject.data.upgradeFire1;
		//this->tempObject1.data.upgradeFire2 = this->tempObject.data.upgradeFire2;
		//this->tempObject1.data.upgradeFire3 = this->tempObject.data.upgradeFire3;
		//this->tempObject1.data.upgradeFire4 = this->tempObject.data.upgradeFire4;
		//this->tempObject1.data.upgradeFire5 = this->tempObject.data.upgradeFire5;
		//this->tempObject1.data.upgradeIce1 = this->tempObject.data.upgradeIce1;
		//this->tempObject1.data.upgradeIce2 = this->tempObject.data.upgradeIce2;
		//this->tempObject1.data.upgradeIce3 = this->tempObject.data.upgradeIce3;
		//this->tempObject1.data.upgradeIce4 = this->tempObject.data.upgradeIce4;
		//this->tempObject1.data.upgradeIce5 = this->tempObject.data.upgradeIce5;
		//this->tempObject1.data.upgradeStone1 = this->tempObject.data.upgradeStone1;
		//this->tempObject1.data.upgradeStone2 = this->tempObject.data.upgradeStone2;
		//this->tempObject1.data.upgradeStone3 = this->tempObject.data.upgradeStone3;
		//this->tempObject1.data.upgradeStone4 = this->tempObject.data.upgradeStone4;
		//this->tempObject1.data.upgradeStone5 = this->tempObject.data.upgradeStone5;
		//this->tempObject1.data.upgradeLevin1 = this->tempObject.data.upgradeLevin1;
		//this->tempObject1.data.upgradeLevin2 = this->tempObject.data.upgradeLevin2;
		//this->tempObject1.data.upgradeLevin3 = this->tempObject.data.upgradeLevin3;
		//this->tempObject1.data.upgradeLevin4 = this->tempObject.data.upgradeLevin4;
		//this->tempObject1.data.upgradeLevin5 = this->tempObject.data.upgradeLevin5;
		//this->tempObject1.data.achieve_firstKill = this->tempObject.data.achieve_firstKill;
		//this->tempObject1.data.achieve_kill_100_enemies = this->tempObject.data.achieve_kill_100_enemies;
		//this->tempObject1.data.achieve_kill_2500_enemies = this->tempObject.data.achieve_kill_2500_enemies;
		//this->tempObject1.data.achieve_call_100_earlyWaves = this->tempObject.data.achieve_call_100_earlyWaves;
		//this->tempObject1.data.achieve_build_100_towers = this->tempObject.data.achieve_build_100_towers;
		//this->tempObject1.data.achieve_createGolem_5_times = this->tempObject.data.achieve_createGolem_5_times;
		//this->tempObject1.data.achieve_createIceman_15_times = this->tempObject.data.achieve_createIceman_15_times;
		//this->tempObject1.data.achieve_createAir_7_times = this->tempObject.data.achieve_createAir_7_times;
		//this->tempObject1.data.achieve_callAllWavesInLevel = this->tempObject.data.achieve_callAllWavesInLevel;
		//this->tempObject1.data.achieve_sellFireIceStoneLevin = this->tempObject.data.achieve_sellFireIceStoneLevin;
		//this->tempObject1.data.achieve_sellFire_10_times = this->tempObject.data.achieve_sellFire_10_times;
		//this->tempObject1.data.achieve_sellIce_10_times = this->tempObject.data.achieve_sellIce_10_times;
		//this->tempObject1.data.achieve_sellStone_10_times = this->tempObject.data.achieve_sellStone_10_times;
		//this->tempObject1.data.achieve_sellLevin_10_times = this->tempObject.data.achieve_sellLevin_10_times;
		//this->tempObject1.data.achieve_golemKill_250_enemies = this->tempObject.data.achieve_golemKill_250_enemies;
		//this->tempObject1.data.achieve_icemanSlowdown_75_enemies = this->tempObject.data.achieve_icemanSlowdown_75_enemies;
		//this->tempObject1.data.achieve_icemanSlowdown_500_enemies = this->tempObject.data.achieve_icemanSlowdown_500_enemies;
		//this->tempObject1.data.achieve_buildUltraTower = this->tempObject.data.achieve_buildUltraTower;
		//this->tempObject1.data.achieve_buildUltraTower_50_times = this->tempObject.data.achieve_buildUltraTower_50_times;
		//this->tempObject1.data.achieve_buildAllUltraTowers = this->tempObject.data.achieve_buildAllUltraTowers;
		//this->tempObject1.data.achieve_notCast = this->tempObject.data.achieve_notCast;
		//this->tempObject1.data.achieve_castFire_150_times = this->tempObject.data.achieve_castFire_150_times;
		//this->tempObject1.data.achieve_castIce_150_times = this->tempObject.data.achieve_castIce_150_times;
		//this->tempObject1.data.achieve_castStone_150_times = this->tempObject.data.achieve_castStone_150_times;
		//this->tempObject1.data.achieve_castLevin_150_times = this->tempObject.data.achieve_castLevin_150_times;
		//this->tempObject1.data.achieve_castGetAll_10_times = this->tempObject.data.achieve_castGetAll_10_times;
		//this->tempObject1.data.achieve_castGetAll_100_times = this->tempObject.data.achieve_castGetAll_100_times;
		//this->tempObject1.data.achieve_castKill_1_enemy = this->tempObject.data.achieve_castKill_1_enemy;
		//this->tempObject1.data.achieve_castKill_100_enemy = this->tempObject.data.achieve_castKill_100_enemy;
		//this->tempObject1.data.achieve_complete_10_hardLevels = this->tempObject.data.achieve_complete_10_hardLevels;
		//this->tempObject1.data.achieve_complete_10_survivalLevels = this->tempObject.data.achieve_complete_10_survivalLevels;
		//this->tempObject1.data.achieve_complete_10_withAllLives = this->tempObject.data.achieve_complete_10_withAllLives;
		//this->tempObject1.data.achieve_dude_01 = this->tempObject.data.achieve_dude_01;
		//this->tempObject1.data.achieve_dude_02 = this->tempObject.data.achieve_dude_02;
		//this->tempObject1.data.achieve_dude_03 = this->tempObject.data.achieve_dude_03;
		//this->tempObject1.data.achieve_dude_04 = this->tempObject.data.achieve_dude_04;
		//this->tempObject1.data.achieve_dude_05 = this->tempObject.data.achieve_dude_05;
		//this->tempObject1.data.achieve_dude_06 = this->tempObject.data.achieve_dude_06;
		//this->tempObject1.data.achieve_dude_07 = this->tempObject.data.achieve_dude_07;
		//this->tempObject1.data.achieve_dude_08 = this->tempObject.data.achieve_dude_08;
		//this->tempObject1.data.achieve_dude_09 = this->tempObject.data.achieve_dude_09;
		//this->tempObject1.data.achieve_dude_10 = this->tempObject.data.achieve_dude_10;
		//this->tempObject1.data.achieve_dude_11 = this->tempObject.data.achieve_dude_11;
		//this->tempObject1.data.achieve_dude_12 = this->tempObject.data.achieve_dude_12;
		//this->tempObject1.data.achieve_dude_13 = this->tempObject.data.achieve_dude_13;
		//this->tempObject1.data.achieve_dude_14 = this->tempObject.data.achieve_dude_14;
		//this->tempObject1.data.addit_killEnemiesCounter = this->tempObject.data.addit_killEnemiesCounter;
		//this->tempObject1.data.addit_earlyWavesCounter = this->tempObject.data.addit_earlyWavesCounter;
		//this->tempObject1.data.addit_buildTowerCounter = this->tempObject.data.addit_buildTowerCounter;
		//this->tempObject1.data.addit_golemCounter = this->tempObject.data.addit_golemCounter;
		//this->tempObject1.data.addit_icemanCounter = this->tempObject.data.addit_icemanCounter;
		//this->tempObject1.data.addit_airCounter = this->tempObject.data.addit_airCounter;
		//this->tempObject1.data.addit_sellFireCounter = this->tempObject.data.addit_sellFireCounter;
		//this->tempObject1.data.addit_sellIceCounter = this->tempObject.data.addit_sellIceCounter;
		//this->tempObject1.data.addit_sellStoneCounter = this->tempObject.data.addit_sellStoneCounter;
		//this->tempObject1.data.addit_sellLevinCounter = this->tempObject.data.addit_sellLevinCounter;
		//this->tempObject1.data.addit_golemKillEnemiesCounter = this->tempObject1.data.addit_golemKillEnemiesCounter;
		//this->tempObject1.data.addit_icemanSlowdownEnemiesCounter = this->tempObject.data.addit_icemanSlowdownEnemiesCounter;
		//this->tempObject1.data.addit_buildUltraTowersCounter = this->tempObject.data.addit_buildUltraTowersCounter;
		//this->tempObject1.data.addit_castFireCounter = this->tempObject.data.addit_castFireCounter;
		//this->tempObject1.data.addit_castIceCounter = this->tempObject.data.addit_castIceCounter;
		//this->tempObject1.data.addit_castStoneCounter = this->tempObject.data.addit_castStoneCounter;
		//this->tempObject1.data.addit_castLevinCounter = this->tempObject.data.addit_castLevinCounter;
		//this->tempObject1.data.addit_castGetAllCounter = this->tempObject.data.addit_castGetAllCounter;
		//this->tempObject1.data.addit_castKillEnemiesCounter = this->tempObject.data.addit_castKillEnemiesCounter;
		//this->tempObject1.data.addit_completeEasyLevelsCounter = this->tempObject.data.addit_completeEasyLevelsCounter;
		//this->tempObject1.data.addit_completeNormalLevelsCounter = this->tempObject.data.addit_completeNormalLevelsCounter;
		//this->tempObject1.data.addit_completeHardLevelsCounter = this->tempObject.data.addit_completeHardLevelsCounter;
		//this->tempObject1.data.addit_completeSurvivalLevelsCounter = this->tempObject.data.addit_completeSurvivalLevelsCounter;
		//this->tempObject1.data.addit_completeLevelsWithAllLivesCounter = this->tempObject.data.addit_completeLevelsWithAllLivesCounter;
		//this->tempObject1.data.addit_levelsDefeatCounter[0] = this->tempObject.data.addit_levelsDefeatCounter[0];
		//this->tempObject1.data.addit_levelsDefeatCounter[1] = this->tempObject.data.addit_levelsDefeatCounter[1];
		//this->tempObject1.data.addit_levelsDefeatCounter[2] = this->tempObject.data.addit_levelsDefeatCounter[2];
		//this->tempObject1.data.addit_levelsDefeatCounter[3] = this->tempObject.data.addit_levelsDefeatCounter[3];
		//this->tempObject1.data.addit_levelsDefeatCounter[4] = this->tempObject.data.addit_levelsDefeatCounter[4];
		//this->tempObject1.data.addit_levelsDefeatCounter[5] = this->tempObject.data.addit_levelsDefeatCounter[5];
		//this->tempObject1.data.addit_levelsDefeatCounter[6] = this->tempObject.data.addit_levelsDefeatCounter[6];
		//this->tempObject1.data.addit_levelsDefeatCounter[7] = this->tempObject.data.addit_levelsDefeatCounter[7];
		//this->tempObject1.data.addit_levelsDefeatCounter[8] = this->tempObject.data.addit_levelsDefeatCounter[8];
		//this->tempObject1.data.addit_levelsDefeatCounter[9] = this->tempObject.data.addit_levelsDefeatCounter[9];
		//this->tempObject1.data.addit_levelsDefeatCounter[10] = this->tempObject.data.addit_levelsDefeatCounter[10];
		//this->tempObject1.data.addit_levelsDefeatCounter[11] = this->tempObject.data.addit_levelsDefeatCounter[11];
		//this->tempObject1.data.addit_levelsDefeatCounter[12] = this->tempObject.data.addit_levelsDefeatCounter[12];
		//this->tempObject1.data.addit_levelsDefeatCounter[13] = this->tempObject.data.addit_levelsDefeatCounter[13];
		//this->tempObject1.data.addit_levelsDefeatCounter[14] = this->tempObject.data.addit_levelsDefeatCounter[14];
		//this->tempObject1.data.training_9 = this->tempObject.data.training_9;
		//this->tempObject1.data.training_91 = this->tempObject.data.training_91;
		//this->tempObject1.data.eduSurvHint = this->tempObject.data.eduSurvHint;
		//if (param1 == 1)
		//{
		//	this->siteSaveConvertionToServer(4);
		//	if (Main.mainClass.IDIClass.idnet)
		//	{
		//		Main.mainClass.IDIClass.saveData(4);
		//	}
		//}
		//else if (param1 == 2)
		//{
		//	this->siteSaveConvertionToServer(5);
		//	if (Main.mainClass.IDIClass.idnet)
		//	{
		//		Main.mainClass.IDIClass.saveData(5);
		//	}
		//}
		//else if (param1 == 3)
		//{
		//	this->siteSaveConvertionToServer(6);
		//	if (Main.mainClass.IDIClass.idnet)
		//	{
		//		Main.mainClass.IDIClass.saveData(6);
		//	}
		//}
		//return;
	};// end function

}
