#include "WorldInterface_mc.h"  
using namespace cocos2d::ui;
#include "cocostudio/DictionaryHelper.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetReader/WidgetReader.h"
using namespace cocostudio;

namespace engine
{
	Hint_mc::Hint_mc() :MovieClip("worldinterface/", "Hint_mc", "Hint_mc")
	{
		SET_NODETYPENAME();
		nameTXT = this->createText("nameTXT");
		noteTXT = this->createText("noteTXT");
		timeTXT = this->createText("timeTXT");
	}
        
	WorldInterface_mc::WorldInterface_mc():MovieClip("worldinterface/", "WorldInterface_mc", "WorldInterface_mc")
	{
		SET_NODETYPENAME();
		//this->container->setPosition(0, Main::SCREEN_HEIGHT);
		//backComponents = this->createMovieClipSub("backComponents");//image
		barInfo = this->createMovieClipSub("barInfo");
		barInfoFireTXT = barInfo->createText("fireTXT");
		barInfoHealthTXT = barInfo->createText("healthTXT");
		barInfoIceTXT = barInfo->createText("iceTXT");
		barInfoLevinTXT = barInfo->createText("levinTXT");
		barInfoMyTarget = NULL;// barInfo->createCase("myTarget");
		barInfoNoteTXT = barInfo->createText("noteTXT");
		barInfoPenaltyTXT = barInfo->createText("penaltyTXT");
		barInfoSpeedTXT = barInfo->createText("speedTXT");
		barInfoStoneTXT = barInfo->createText("stoneTXT");
		book = this->createMovieClipSub("book");
		bookBookCase = book->createCase("bookCase");
		butCastAir = this->createMovieClipSub("butCastAir");
		butCastAirCastAirCase = butCastAir->createCase("castAirCase");

		butCastAirCont = butCastAir->createMovieClipSub("cont");//

		butCastAirContContMask = butCastAirCont->createMask("contMask");
		//butCastAirContContMask = butCastAirCont->createMovieClipSub("contMask");

		butCastGolem = this->createMovieClipSub("butCastGolem"); 
		butCastGolemCastGolemCase = butCastGolem->createCase("castGolemCase");

		butCastGolemCont = butCastGolem->createMovieClipSub("cont");
		butCastGolemContContMask = butCastGolemCont->createMovieClipSub("contMask");
		butCastIceman = this->createMovieClipSub("butCastIceman");
		butCastIcemanCastIcemanCase = butCastIceman->createCase("castIcemanCase");
		butCastIcemanCont = butCastIceman->createMovieClipSub("cont");
		butCastIcemanContContMask = butCastIcemanCont->createMovieClipSub("contMask");
		buyFire = this->createMovieClipSub("buyFire");
		buyFireBuyTXT = buyFire->createText("buyTXT");
		buyFireCoin = buyFire->createMovieClipSub("coin");
		buyFireLightUp = buyFire->getSprite("lightUp");
		buyGetAll = this->createMovieClipSub("buyGetAll");
		buyGetAllBuyTXT = buyGetAll->createText("buyTXT");
		buyGetAllCoin = buyGetAll->createMovieClipSub("coin");
		buyGetAllLightUp = buyGetAll->getSprite("lightUp");
		buyIce = this->createMovieClipSub("buyIce");
		buyIceBuyTXT = buyIce->createText("buyTXT");
		buyIceCoin = buyIce->createMovieClipSub("coin");
		buyIceLightUp = buyIce->getSprite("lightUp");
		buyLevin = this->createMovieClipSub("buyLevin");
		buyLevinBuyTXT = buyLevin->createText("buyTXT");
		buyLevinCoin = buyLevin->createMovieClipSub("coin");
		buyLevinLightUp = buyLevin->getSprite("lightUp");
		buyStone = this->createMovieClipSub("buyStone");
		buyStoneBuyTXT = buyStone->createText("buyTXT");
		buyStoneCoin = buyStone->createMovieClipSub("coin");
		buyStoneLightUp = buyStone->getSprite("lightUp");
		fast = this->createMovieClipSub("fast");
		fastFastCase = fast->createCase("fastCase");
		fastCont = fast->createMovieClipSub("cont");
		fireBack = this->createMovieClipSub("fireBack");
		fireBackCont = fireBack->createMovieClipSub("cont");
		fireBacklight = this->createMovieClipSub("fireBacklight");
		fireNumTXT = this->createText("fireNumTXT");
 		fireSphere = this->createMovieClipSub("fireSphere");
		 
		//Vec2 pos = this->fireSphere->convertToWorldSpace(Vec2(0, 0));
		//Vec2 wp = this->container->convertToNodeSpaceAR(pos);
		//logInfo("fireSphere", pos, &wp);
		//this->fireSphere->setPosition(wp);
		//logInfo("fireSphere", this->fireSphere ->getPosition());
		//logInfo("this->fireSphere->display", getNamePath(this->fireSphere->display));
 
		fireSphereSphereCase = fireSphere->createCase("sphereCase");
		getAll = this->createMovieClipSub("getAll");
		getAllFire = getAll->createMovieClipSub("fire");
		getAllIce = getAll->createMovieClipSub("ice");
		getAllLevin = getAll->createMovieClipSub("levin");
		getAllSphereCase = getAll->createCase("sphereCase");
		getAllStone = getAll->createMovieClipSub("stone");
		getAllNumTXT = this->createText("getAllNumTXT");
		iceBack = this->createMovieClipSub("iceBack");
		iceBackCont = iceBack->createMovieClipSub("cont");
		iceBacklight = this->createMovieClipSub("iceBacklight");
		iceNumTXT = this->createText("iceNumTXT");
		iceSphere = this->createMovieClipSub("iceSphere");
		iceSphereSphereCase = iceSphere->createCase("sphereCase");
		lastTime = this->createText("lastTime");
		levinBack = this->createMovieClipSub("levinBack");
		levinBackCont = levinBack->createMovieClipSub("cont");
		levinBacklight = this->createMovieClipSub("levinBacklight");
		levinNumTXT = this->createText("levinNumTXT");
		levinSphere = this->createMovieClipSub("levinSphere");
		levinSphereSphereCase = levinSphere->createCase("sphereCase");
		liveTXT = this->createText("liveTXT");
		moneyTXT = this->createText("moneyTXT");
		pause = this->createMovieClipSub("pause");
		pausePauseCase = pause->createCase("pauseCase");
		selectUnit = this->createMovieClipSub("selectUnit");
		sell = this->createMovieClipSub("sell");
		slow = this->createMovieClipSub("slow");
		startWaves = this->createMovieClipSub("startWaves");
		startWavesStartWavesCase = startWaves->createCase("startWavesCase");
		stoneBack = this->createMovieClipSub("stoneBack");
		stoneBackCont = stoneBack->createMovieClipSub("cont");
		stoneBacklight = this->createMovieClipSub("stoneBacklight");
		stoneNumTXT = this->createText("stoneNumTXT");
		stoneSphere = this->createMovieClipSub("stoneSphere");
		stoneSphereSphereCase = stoneSphere->createCase("sphereCase");
		testRestart = this->createMovieClipSub("testRestart");
		testRestartBoard = this->createMovieClipSub("testRestartBoard");
		testRestartBoardWaveTXT = testRestartBoard->createText("waveTXT");
		waveTXT = this->createText("waveTXT");
		MCText * wavesTXT = this->createText("wavesTXT");
		std::setText(wavesTXT, "波次:");
		traceBezier=NULL;

		this->pauseOpenFlag = 0;
		this->pauseCloseFlag = 0;
		this->bookOpenFlag = 0;
		this->bookCloseFlag = 0;
		this->fireSphereOpened = 0;
		this->iceSphereOpened = 0;
		this->stoneSphereOpened = 0;
		this->levinSphereOpened = 0;
		this->getAllOpened = 0;
		this->fireBacklightTurnFlag = 0;
		this->iceBacklightTurnFlag = 0;
		this->stoneBacklightTurnFlag = 0;
		this->levinBacklightTurnFlag = 0;
		this->buyFireMyCost = 0;
		this->buyIceMyCost = 0;
		this->buyStoneMyCost = 0;
		this->buyLevinMyCost = 0;
		this->buyGetAllMyCost = 0;
		this->getAll->gotoAndStop(3);
		this->fireBack->gotoAndStop(3);
		this->iceBack->gotoAndStop(3);
		this->stoneBack->gotoAndStop(3);
		this->levinBack->gotoAndStop(3);
	};
	
	
}
