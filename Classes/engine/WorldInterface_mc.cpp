#include "WorldInterface_mc.h"  
using namespace cocos2d::ui;
//#include "cocostudio/DictionaryHelper.h"
//#include "cocostudio/CocoStudio.h"
//#include "cocostudio/WidgetReader/WidgetReader.h"
//using namespace cocostudio;

namespace engine
{
	Hint_mc::Hint_mc() :MovieClip("worldinterface/", "Hint_mc", "Hint_mc")
	{
		SET_NODETYPENAME();
		nameTXT = this->createText("nameTXT");
		noteTXT = this->createText("noteTXT");
		timeTXT = this->createText("timeTXT");
	}
	
    //实现遮罩的两种方法
    //auto clip = CCClippingNode::create();
    //auto stencil = CCSprite::create("mask.png");
    //clip->setStencil(stencil);
    //clip->setInverted(false);
    //clip->setAlphaThreshold(0);
    //clip->addChild(CCSprite::create("head.png"));
   
	WorldInterface_mc::WorldInterface_mc()
	{
		SET_NODETYPENAME();
	}
	bool WorldInterface_mc::init(){
		MovieClip * wiBook = new MovieClip("worldinterface/", "worldBook_mc", "worldBook_mc");
		MovieClip * wiCast = new MovieClip("worldinterface/", "worldCast_mc", "worldCast_mc");
		MovieClip * wiLive = new MovieClip("worldinterface/", "worldLive_mc", "worldLive_mc");
		MovieClip * wiSphere = new MovieClip("worldinterface/", "worldSphere_mc", "worldSphere_mc");
		MovieClip * wiStart=new MovieClip("worldinterface/", "worldStart_mc", "worldStart_mc");

		this->addChild(wiBook);
		this->addChild(wiCast);
		this->addChild(wiLive);
		this->addChild(wiSphere);
		this->addChild(wiStart);

		lastTime = new MCText();// this->createText("lastTime");
		this->addChild(lastTime);

		//this->setPosition(0, Main::SCREEN_HEIGHT);
		//backComponents = this->createMovieClipSub("backComponents");//image
		//barInfo = this->createMovieClipSub("barInfo");
		//barInfoFireTXT = barInfo->createText("fireTXT");
		//barInfoHealthTXT = barInfo->createText("healthTXT");
		//barInfoIceTXT = barInfo->createText("iceTXT");
		//barInfoLevinTXT = barInfo->createText("levinTXT");
		//barInfoMyTarget = NULL;// barInfo->createCase("myTarget");
		//barInfoNoteTXT = barInfo->createText("noteTXT");
		//barInfoPenaltyTXT = barInfo->createText("penaltyTXT");
		//barInfoSpeedTXT = barInfo->createText("speedTXT");
		//barInfoStoneTXT = barInfo->createText("stoneTXT");
		book = wiBook->createMovieClipSub("book",true);
		bookBookCase = book->createCase("bookCase",true);

		butCastAir = wiCast->createMovieClipSub("butCastAir");
		butCastAirCastAirCase = butCastAir->createCase("castAirCase");

		butCastAirCont = butCastAir->createMovieClipSub("cont", true);//4帧才有

		butCastAirContContMask = butCastAirCont->createMask("contMask");
		//butCastAirContContMask = butCastAirCont->createMovieClipSub("contMask");

		butCastGolem = wiCast->createMovieClipSub("butCastGolem"); 
		butCastGolemCastGolemCase = butCastGolem->createCase("castGolemCase");

		butCastGolemCont = butCastGolem->createMovieClipSub("cont", true);//4帧才有
		butCastGolemContContMask = butCastGolemCont->createMask("contMask");
		butCastIceman = wiCast->createMovieClipSub("butCastIceman");
		butCastIcemanCastIcemanCase = butCastIceman->createCase("castIcemanCase");
		butCastIcemanCont = butCastIceman->createMovieClipSub("cont", true);//4帧才有
        butCastIcemanContContMask = butCastIcemanCont->createMask("contMask");

		buyFire = wiSphere->createMovieClipSub("buyFire");
		buyFireBuyTXT = buyFire->createText("buyTXT");
		buyFireCoin = buyFire->createMovieClipSub("coin");
		buyFireLightUp = buyFire->getSprite("lightUp");
		buyGetAll = wiSphere->createMovieClipSub("buyGetAll");
		buyGetAllBuyTXT = buyGetAll->createText("buyTXT");
		buyGetAllCoin = buyGetAll->createMovieClipSub("coin");
		buyGetAllLightUp = buyGetAll->getSprite("lightUp");
		buyIce = wiSphere->createMovieClipSub("buyIce");
		buyIceBuyTXT = buyIce->createText("buyTXT");
		buyIceCoin = buyIce->createMovieClipSub("coin");
		buyIceLightUp = buyIce->getSprite("lightUp");
		buyLevin = wiSphere->createMovieClipSub("buyLevin");
		buyLevinBuyTXT = buyLevin->createText("buyTXT");
		buyLevinCoin = buyLevin->createMovieClipSub("coin");
		buyLevinLightUp = buyLevin->getSprite("lightUp");
		buyStone = wiSphere->createMovieClipSub("buyStone");
		buyStoneBuyTXT = buyStone->createText("buyTXT");
		buyStoneCoin = buyStone->createMovieClipSub("coin");
		buyStoneLightUp = buyStone->getSprite("lightUp");

		fast = wiStart->createMovieClipSub("fast");
		fastFastCase = fast->createCase("fastCase");
		fastCont = fast->createMovieClipSub("cont", true);// 4 5帧 才有

 		fireSphere = wiSphere->createMovieClipSub("fireSphere");
		fireBack = wiSphere->createMovieClipSub("fireBack");
		fireBackCont = fireBack->createMovieClipSub("cont", true);// 2帧 才有
		fireBacklight = wiSphere->createMovieClipSub("fireBacklight");
		fireNumTXT = wiSphere->createText("fireNumTXT");
		 
		//Vec2 pos = this->fireSphere->convertToWorldSpace(Vec2(0, 0));
		//Vec2 wp = this->container->convertToNodeSpaceAR(pos);
		//logInfo("fireSphere", pos, &wp);
		//this->fireSphere->setPosition(wp);
		//logInfo("fireSphere", this->fireSphere ->getPosition());
		//logInfo("this->fireSphere->display", getNamePath(this->fireSphere->display));
 
		fireSphereSphereCase = fireSphere->createCase("sphereCase",false);
		getAll = wiSphere->createMovieClipSub("getAll");
		getAllFire = getAll->createMovieClipSub("fire");
		getAllIce = getAll->createMovieClipSub("ice");
		getAllLevin = getAll->createMovieClipSub("levin");
		getAllSphereCase = getAll->createCase("sphereCase", false);
		getAllStone = getAll->createMovieClipSub("stone");
		getAllNumTXT = wiSphere->createText("getAllNumTXT");
		iceBack = wiSphere->createMovieClipSub("iceBack");
		iceBackCont = iceBack->createMovieClipSub("cont", true);//2帧 才有
		iceBacklight = wiSphere->createMovieClipSub("iceBacklight");
		iceNumTXT = wiSphere->createText("iceNumTXT");
		iceSphere = wiSphere->createMovieClipSub("iceSphere");
		iceSphereSphereCase = iceSphere->createCase("sphereCase", false);
		levinBack = wiSphere->createMovieClipSub("levinBack");
		levinBackCont = levinBack->createMovieClipSub("cont", true);//2帧 才有
		levinBacklight = wiSphere->createMovieClipSub("levinBacklight");
		levinNumTXT = wiSphere->createText("levinNumTXT");
		levinSphere = wiSphere->createMovieClipSub("levinSphere");
		levinSphereSphereCase = levinSphere->createCase("sphereCase", false);
		liveTXT = wiLive->createText("liveTXT");
		moneyTXT = wiLive->createText("moneyTXT");

		pause = wiBook->createMovieClipSub("pause");
		pausePauseCase = pause->createCase("pauseCase",true);
		//selectUnit = this->createMovieClipSub("selectUnit");
		sell = wiBook->createMovieClipSub("sell");
		//slow = this->createMovieClipSub("slow");
		startWaves = wiStart->createMovieClipSub("startWaves");
		startWavesStartWavesCase = startWaves->createCase("startWavesCase");

		stoneBack = wiSphere->createMovieClipSub("stoneBack");
		stoneBackCont = stoneBack->createMovieClipSub("cont",true);//2帧 才有
		stoneBacklight = wiSphere->createMovieClipSub("stoneBacklight");
		stoneNumTXT = wiSphere->createText("stoneNumTXT");
		stoneSphere = wiSphere->createMovieClipSub("stoneSphere");
		stoneSphereSphereCase = stoneSphere->createCase("sphereCase", false);
		//testRestart = this->createMovieClipSub("testRestart");
		//testRestartBoard = this->createMovieClipSub("testRestartBoard");
		//testRestartBoardWaveTXT = testRestartBoard->createText("waveTXT");
		waveTXT = wiLive->createText("waveTXT");
		MCText * wavesTXT = wiLive->createText("wavesTXT");
		std::setText(wavesTXT, I18N_VALUE(I18N_CODE::U071));
		//traceBezier=NULL;

		wiBook->setPosition(Vec2(Main::SCREEN_WIDTH - 5, Main::SCREEN_HEIGHT-5 ));
		wiCast->setPosition(Vec2(10, 10));
		wiLive->setPosition(Vec2(10, Main::SCREEN_HEIGHT -5));
		wiSphere->setPosition(Vec2(220, Main::SCREEN_HEIGHT));
		wiStart->setPosition(Vec2(Main::SCREEN_WIDTH - 230, 5));


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

		return BaseNode::init();
	};
	
	
}
