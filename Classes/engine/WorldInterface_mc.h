#ifndef WORLD_INTERFACE_MC_H
#define WORLD_INTERFACE_MC_H
#include "BaseHeaders.h"

namespace engine
{
	struct GetAchieve_mc :public  MovieClip
	{
		MovieClipSub * icon;
		MovieClipSub * board;
		ui::Text * boardNoteTXT;
		//MovieClip * board;
		inline GetAchieve_mc::GetAchieve_mc() :MovieClip("worldinterface/", "GetAchieve_mc", "GetAchieve_mc")
		{
			board = this->createMovieClipSub("board");
			boardNoteTXT = board->createText("noteTXT");
			icon = this->createMovieClipSub("icon");
		}; 
	}; 
    
	class WorldInterface_mc :public MovieClip
	{
	public:
		//MovieClipSub * backComponents;
		MovieClipSub * barInfo;
		ui::Text     * barInfoFireTXT;
		ui::Text     * barInfoHealthTXT;
		ui::Text     * barInfoIceTXT;
		ui::Text     * barInfoLevinTXT;
		BaseNode     * barInfoMyTarget;
		ui::Text     * barInfoNoteTXT;
		ui::Text     * barInfoPenaltyTXT;
		ui::Text     * barInfoSpeedTXT;
		ui::Text     * barInfoStoneTXT;
		MovieClipSub * book;
		BaseNode     * bookBookCase;
		MovieClipSub * butCastAir;
		BaseNode     * butCastAirCastIcemanCase;
		MovieClipSub * butCastAirCont;
		MovieClipSub * butCastAirContContMask;
		MovieClipSub * butCastGolem;
		BaseNode     * butCastGolemCastIcemanCase;
		MovieClipSub * butCastGolemCont;
		MovieClipSub * butCastGolemContContMask;
		MovieClipSub * butCastIceman;
		BaseNode     * butCastIcemanCastIcemanCase;
		MovieClipSub * butCastIcemanCont;
		MovieClipSub * butCastIcemanContContMask;
		MovieClipSub * buyFire;
		ui::Text     * buyFireBuyTXT;
		MovieClipSub * buyFireCoin;
		MovieClipSub * buyFireLightUp;
		MovieClipSub * buygetAll;
		ui::Text     * buygetAllBuyTXT;
		MovieClipSub * buygetAllCoin;
		MovieClipSub * buygetAllLightUp;
		MovieClipSub * buyIce;
		ui::Text     * buyIceBuyTXT;
		MovieClipSub * buyIceCoin;
		MovieClipSub * buyIceLightUp;
		MovieClipSub * buyLevin;
		ui::Text     * buyLevinBuyTXT;
		MovieClipSub * buyLevinCoin;
		MovieClipSub * buyLevinLightUp;
		MovieClipSub * buyStone;
		ui::Text     * buyStoneBuyTXT;
		MovieClipSub * buyStoneCoin;
		MovieClipSub * buyStoneLightUp;
		MovieClipSub * fast;
		BaseNode     * fastFastCase;
		MovieClipSub * fastCont;
		MovieClipSub * fireBack;
		MovieClipSub * fireBackCont;
		MovieClipSub * fireBacklight;
		ui::Text     * fireNumTXT;
		MovieClipSub * firePrice;
		MovieClipSub * fireSphere;
		BaseNode     * fireSphereSphereCase;
		MovieClipSub * getAll;
		MovieClipSub * getAllFire;
		MovieClipSub * getAllIce;
		MovieClipSub * getAllLevin;
		BaseNode     * getAllSphereCase;
		MovieClipSub * getAllStone;
		ui::Text     * getAllNumTXT;
		MovieClipSub * iceBack;
		MovieClipSub * iceBackCont;
		MovieClipSub * iceBacklight;
		ui::Text     * iceNumTXT;
		MovieClipSub * iceSphere;
		BaseNode     * iceSphereSphereCase;
		ui::Text     * lastTime;
		MovieClipSub * levinBack;
		MovieClipSub * levinBackCont;
		MovieClipSub * levinBacklight;
		ui::Text     * levinNumTXT;
		MovieClipSub * levinSphere;
		BaseNode     * levinSphereSphereCase;
		ui::Text     * liveTXT;
		ui::Text     * moneyTXT;
		MovieClipSub * pause;
		BaseNode     * pausePauseCase;
		MovieClipSub * selectUnit;
		MovieClipSub * sell;
		MovieClipSub * slow;
		MovieClipSub * startWaves;
		BaseNode     * startWavesStartWavesCase;
		MovieClipSub * stoneBack;
		MovieClipSub * stoneBackCont;
		MovieClipSub * stoneBacklight;
		ui::Text     * stoneNumTXT;
		MovieClipSub * stoneSphere;
		BaseNode     * stoneSphereSphereCase;
		MovieClipSub * testRestart;
		MovieClipSub * testRestartBoard;
		ui::Text     * testRestartBoardWaveTXT;
		ui::Text     * waveTXT;
		
		WorldInterface_mc();
    };


}
#endif
