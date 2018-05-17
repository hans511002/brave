#ifndef WORLD_INTERFACE_MC_H
#define WORLD_INTERFACE_MC_H
#include "BaseHeaders.h"


namespace engine
{
    struct GetAchieve_mc  :public  MovieClip
    {
        MovieClip* board;
        MovieClip* icon;
        GetAchieve_mc();
    }
    
	class WorldInterface_mc :public BaseNode
	{
	public:

		//public var backComponents : MovieClip;
		//barInfo : MovieClip;
        Sprite * barinfoback;
        Sprite * healthbar;
        Sprite * moneybar;


     
		//public var book : MovieClip;
        Sprite *  btncastback;
        Sprite * butCastAir;// : MovieClip;
        Sprite * butCastGolem;// : MovieClip;
        Sprite * butCastIceman;// : MovieClip;


        Sprite *  sphereback;
        Sprite * iceBack;//public var iceBack : MovieClip;
        Sprite * fireBack;//public var fireBack : MovieClip;
        Sprite * levinBack;//public var levinBack : MovieClip;
        Sprite * stoneBack;// : MovieClip;
        Sprite  * allSphereBack; 
          
        Sprite  * buyFire;//: MovieClip;
        Sprite  * buyIce;// : MovieClip;
        Sprite  * buyLevin;//: MovieClip;
        Sprite  * buyStone;//: MovieClip;
        Sprite  * buyGetAll;//: MovieClip; 

        Sprite *iceSphere;//public var iceSphere : MovieClip;
        Sprite *fireSphere;//public var fireSphere : MovieClip;
        Sprite *levinSphere;//public var levinSphere : MovieClip;
        Sprite *stoneSphere;// stoneSphere public var stoneSphere : MovieClip;
        Sprite *allSphere;// stoneSphere public var stoneSphere : MovieClip;

 

		MovieClip * stoneBacklight;//public var stoneBacklight : MovieClip;
		MovieClip * levinBacklight;//public var levinBacklight : MovieClip;
		MovieClip * iceBacklight;//public var iceBacklight : MovieClip;
		MovieClip * fireBacklight;//public var fireBacklight : MovieClip;

        MovieClip * stoneBacked; 
        MovieClip * levinBacked; 
        MovieClip * iceBacked; 
        MovieClip * fireBacked; 

	
		//public var testRestart : MovieClip;
		//public var testRestartBoard : MovieClip;
		//public var traceBezier : MovieClip;
		ui::Text * lastTime;// public var lastTime : TextField;
		ui::Text  * waveTXT;// public var waveTXT : TextField;
		ui::Text * liveTXT;// : TextField;
		ui::Text * moneyTXT;//: TextField;
		ui::Text * levinNumTXT;// : TextField;
		ui::Text * iceNumTXT;//: TextField;
		ui::Text * fireNumTXT;// : TextField;
		ui::Text * stoneNumTXT;//public var stoneNumTXT : TextField;
		ui::Text * getAllNumTXT; // public var getAllNumTXT : TextField;
        
        ui::Text * firePrice;
        ui::Text * icePrice;
        ui::Text *  stonePrice;
        ui::Text *  levinPrice;
        ui::Text *  getAllPrice;


        ui::Button * pause; //public var pause : MovieClip;
        Sprite * startbtnback;
        ui::Button * startWaves;// public var startWaves : MovieClip;

        ui::Button  * fastbtn;//BaseNode * fastbtned;
        //public var sell : MovieClip;
        dragonBones::CCArmatureDisplay * faster;

        virtual void onEnter();
        virtual void onExit();
        

		WorldInterface_mc();
        void WorldInterface_mc::startWavesCallback(Ref* pSender);
		virtual bool init();
        void mouseDownHandler(cocos2d::Event *event);
    };


}
#endif
