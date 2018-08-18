#ifndef WORLD_INTERFACE_MC_H
#define WORLD_INTERFACE_MC_H
#include "BaseHeaders.h"

namespace engine
{
    struct Hint_mc : public MovieClip
    {
        MCText * nameTXT;
        MCText * noteTXT;
        MCText * timeTXT;
        Hint_mc();
    };
	
	struct GetAchieve_mc :public  MovieClip
	{
		MovieClipSub * icon;
		MovieClipSub * board;
		MCText * boardNoteTXT;
	    bool closeFlag;
		string myText;
		int counter;
		inline GetAchieve_mc() :MovieClip("worldinterface/", "GetAchieve_mc", "GetAchieve_mc")
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
		MCText     * barInfoFireTXT;
		MCText     * barInfoHealthTXT;
		MCText     * barInfoIceTXT;
		MCText     * barInfoLevinTXT;
		Node         * barInfoMyTarget;
		MCText     * barInfoNoteTXT;
		MCText     * barInfoPenaltyTXT;
		MCText     * barInfoSpeedTXT;
		MCText     * barInfoStoneTXT;
		MovieClipSub * book;
		MCCase     * bookBookCase;
		MovieClipSub * butCastAir;
		MCCase * butCastAirCastAirCase;
 		MovieClipSub * butCastAirCont;
		MCMask     * butCastAirContContMask;
		MovieClipSub * butCastGolem;
		MCCase * butCastGolemCastGolemCase;
		MovieClipSub * butCastGolemCont;
		MCMask * butCastGolemContContMask;
		MovieClipSub * butCastIceman; 
		 MCCase     * butCastIcemanCastIcemanCase;
		MovieClipSub * butCastIcemanCont;
		MCMask * butCastIcemanContContMask;
		MovieClipSub * buyFire;
		MCText     * buyFireBuyTXT;
		MovieClipSub * buyFireCoin;
		Sprite * buyFireLightUp;
		MovieClipSub * buyGetAll;
		MCText     * buyGetAllBuyTXT;
		MovieClipSub * buyGetAllCoin;
		Sprite * buyGetAllLightUp;
		MovieClipSub * buyIce;
		MCText     * buyIceBuyTXT;
		MovieClipSub * buyIceCoin;
		Sprite * buyIceLightUp;
		MovieClipSub * buyLevin;
		MCText     * buyLevinBuyTXT;
		MovieClipSub * buyLevinCoin;
		Sprite * buyLevinLightUp;
		MovieClipSub * buyStone;
		MCText     * buyStoneBuyTXT;
		MovieClipSub * buyStoneCoin;
		Sprite * buyStoneLightUp;
		MovieClipSub * fast;
		MCCase     * fastFastCase;
		MovieClipSub * fastCont;
		MovieClipSub * fireBack;
		MovieClipSub * fireBackCont;
		MovieClipSub * fireBacklight;
		MCText     * fireNumTXT; 
		MovieClipSub * fireSphere;
		MCCase     * fireSphereSphereCase;
		MovieClipSub * getAll;
		MovieClipSub * getAllFire;
		MovieClipSub * getAllIce;
		MovieClipSub * getAllLevin;
		MCCase     * getAllSphereCase;
		MovieClipSub * getAllStone;
		MCText     * getAllNumTXT;
		MovieClipSub * iceBack;
		MovieClipSub * iceBackCont;
		MovieClipSub * iceBacklight;
		MCText     * iceNumTXT;
		MovieClipSub * iceSphere;
		MCCase     * iceSphereSphereCase;
		MCText     * lastTime;
		MovieClipSub * levinBack;
		MovieClipSub * levinBackCont;
		MovieClipSub * levinBacklight;
		MCText     * levinNumTXT;
		MovieClipSub * levinSphere;
		MCCase     * levinSphereSphereCase;
		MCText     * liveTXT;
		MCText     * moneyTXT;
		MovieClipSub * pause;
		MCCase     * pausePauseCase;
		MovieClipSub * sell;
		MovieClipSub * slow;
		MovieClipSub * startWaves;
		MCCase     * startWavesStartWavesCase;
		MovieClipSub * stoneBack;
		MovieClipSub * stoneBackCont;
		MovieClipSub * stoneBacklight;
		MCText     * stoneNumTXT;
		MovieClipSub * stoneSphere;
		MCCase     * stoneSphereSphereCase;
		MovieClipSub * testRestart;
		MovieClipSub * testRestartBoard;
		MCText     * testRestartBoardWaveTXT;
		MCText     * waveTXT;
		MCCase     * traceBezier;
		
		WorldInterface_mc();
		
		///////////////////////////
        Vec2 fireSphereMyPoint  ;
		Vec2 iceSphereMyPoint   ;
		Vec2 stoneSphereMyPoint ;
		Vec2 levinSphereMyPoint ;
		Vec2 getAllMyPoint      ;
		
		bool pauseOpenFlag;
		bool pauseCloseFlag;
		bool bookOpenFlag;
		bool bookCloseFlag;
		
		bool fireSphereOpened;
		bool iceSphereOpened;
		bool stoneSphereOpened;
		bool levinSphereOpened;
		bool getAllOpened;
		
		bool fireBacklightTurnFlag;
		bool iceBacklightTurnFlag;
		bool stoneBacklightTurnFlag;
		bool levinBacklightTurnFlag;

		int buyFireMyCost;
		Vec2 buyFireCoinMyPoint;
		int buyIceMyCost;
		Vec2 buyIceCoinMyPoint;
		int buyStoneMyCost;
		Vec2 buyStoneCoinMyPoint;
		int buyLevinMyCost;
		Vec2 buyLevinCoinMyPoint;
		int buyGetAllMyCost;
		Vec2 buyGetAllCoinMyPoint;

    };


}
#endif
