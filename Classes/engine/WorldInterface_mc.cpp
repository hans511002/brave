#include "WorldInterface_mc.h"  
using namespace cocos2d::ui;
#include "cocostudio/DictionaryHelper.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetReader/WidgetReader.h"
using namespace cocostudio;

namespace engine
{
    Hint_mc:Hint_mc():MovieClip("worldinterface/", "Hint_mc", "Hint_mc")
    {
        	nameTXT	=this	->createText	("nameTXT");
            noteTXT	=this	->createText	("noteTXT");
            timeTXT	=this	->createText	("timeTXT");

    }    
        
	WorldInterface_mc::WorldInterface_mc()
		:MovieClip("worldinterface/", "WorldInterface_mc", "WorldInterface_mc")
	{
		//backComponents = this->createMovieClipSub("backComponents");//image
		barInfo = this->createMovieClipSub("barInfo");
		barInfoFireTXT = barInfo->createText("fireTXT");
		barInfoHealthTXT = barInfo->createText("healthTXT");
		barInfoIceTXT = barInfo->createText("iceTXT");
		barInfoLevinTXT = barInfo->createText("levinTXT");
		barInfoMyTarget = barInfo->createCase("myTarget");
		barInfoNoteTXT = barInfo->createText("noteTXT");
		barInfoPenaltyTXT = barInfo->createText("penaltyTXT");
		barInfoSpeedTXT = barInfo->createText("speedTXT");
		barInfoStoneTXT = barInfo->createText("stoneTXT");
		book = this->createMovieClipSub("book");
		bookBookCase = book->createCase("bookCase");
		butCastAir = this->createMovieClipSub("butCastAir");
		butCastAirCastIcemanCase = butCastAir->createCase("castIcemanCase");
		butCastAirCont = butCastAir->createMovieClipSub("cont");
		butCastAirContContMask = butCastAirCont->createMovieClipSub("contMask");

		butCastGolem = this->createMovieClipSub("butCastGolem");
		butCastGolemCastIcemanCase = butCastGolem->createCase("castIcemanCase");
		butCastGolemCont = butCastGolem->createMovieClipSub("cont");
		butCastGolemContContMask = butCastGolemCont->createMovieClipSub("contMask");
		butCastIceman = this->createMovieClipSub("butCastIceman");
		butCastIcemanCastIcemanCase = butCastIceman->createCase("castIcemanCase");
		butCastIcemanCont = butCastIceman->createMovieClipSub("cont");
		butCastIcemanContContMask = butCastIcemanCont->createMovieClipSub("contMask");
		buyFire = this->createMovieClipSub("buyFire");
		buyFireBuyTXT = buyFire->createText("buyTXT");
		buyFireCoin = buyFire->createMovieClipSub("coin");
		buyFireLightUp = buyFire->createMovieClipSub("lightUp");
		buygetAll = this->createMovieClipSub("buygetAll");
		buygetAllBuyTXT = buygetAll->createText("buyTXT");
		buygetAllCoin = buygetAll->createMovieClipSub("coin");
		buygetAllLightUp = buygetAll->createMovieClipSub("lightUp");
		buyIce = this->createMovieClipSub("buyIce");
		buyIceBuyTXT = buyIce->createText("buyTXT");
		buyIceCoin = buyIce->createMovieClipSub("coin");
		buyIceLightUp = buyIce->createMovieClipSub("lightUp");
		buyLevin = this->createMovieClipSub("buyLevin");
		buyLevinBuyTXT = buyLevin->createText("buyTXT");
		buyLevinCoin = buyLevin->createMovieClipSub("coin");
		buyLevinLightUp = buyLevin->createMovieClipSub("lightUp");
		buyStone = this->createMovieClipSub("buyStone");
		buyStoneBuyTXT = buyStone->createText("buyTXT");
		buyStoneCoin = buyStone->createMovieClipSub("coin");
		buyStoneLightUp = buyStone->createMovieClipSub("lightUp");
		fast = this->createMovieClipSub("fast");
		fastFastCase = fast->createCase("fastCase");
		fastCont = fast->createMovieClipSub("cont");
		fireBack = this->createMovieClipSub("fireBack");
		fireBackCont = fireBack->createMovieClipSub("cont");
		fireBacklight = this->createMovieClipSub("fireBacklight");
		fireNumTXT = this->createText("fireNumTXT");
		firePrice = this->createMovieClipSub("firePrice");
		fireSphere = this->createMovieClipSub("fireSphere");
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
	};
}
