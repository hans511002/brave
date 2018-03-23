#ifndef WORLD_INTERFACE_MC_H
#define WORLD_INTERFACE_MC_H
#include "BaseHeaders.h"


namespace engine
{
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
        Sprite  * getAll;////public var getAll : MovieClip; allsphere

        Sprite  * buyFire;//: MovieClip;
        Sprite  * buyIce;// : MovieClip;
        Sprite  * buyLevin;//: MovieClip;
        Sprite  * buyStone;//: MovieClip;
        Sprite  * buyGetAll;//: MovieClip; 

        Sprite *iceSphere;//public var iceSphere : MovieClip;
        Sprite *fireSphere;//public var fireSphere : MovieClip;
        Sprite *levinSphere;//public var levinSphere : MovieClip;
        Sprite *stoneSphere;// stoneSphere public var stoneSphere : MovieClip;

 

		dragonBones::DBCCArmatureNode * stoneBacklight;//public var stoneBacklight : MovieClip;
		dragonBones::DBCCArmatureNode * levinBacklight;//public var levinBacklight : MovieClip;
		dragonBones::DBCCArmatureNode * iceBacklight;//public var iceBacklight : MovieClip;
		dragonBones::DBCCArmatureNode * fireBacklight;//public var fireBacklight : MovieClip;

        dragonBones::DBCCArmatureNode * stoneBacked; 
        dragonBones::DBCCArmatureNode * levinBacked; 
        dragonBones::DBCCArmatureNode * iceBacked; 
        dragonBones::DBCCArmatureNode * fireBacked; 

	
		//public var testRestart : MovieClip;
		//public var testRestartBoard : MovieClip;
		//public var traceBezier : MovieClip;
		cocos2d::TextFieldTTF * lastTime;// public var lastTime : TextField;
		cocos2d::TextFieldTTF  * waveTXT;// public var waveTXT : TextField;
		cocos2d::TextFieldTTF * liveTXT;// : TextField;
		cocos2d::TextFieldTTF * moneyTXT;//: TextField;
		cocos2d::TextFieldTTF * levinNumTXT;// : TextField;
		cocos2d::TextFieldTTF * iceNumTXT;//: TextField;
		cocos2d::TextFieldTTF * fireNumTXT;// : TextField;
		cocos2d::TextFieldTTF * stoneNumTXT;//public var stoneNumTXT : TextField;

		cocos2d::TextFieldTTF * getAllNumTXT; // public var getAllNumTXT : TextField;
        ui::Button * pause; //public var pause : MovieClip;
        
        Sprite * startbtnback;
        ui::Button * startWaves;// public var startWaves : MovieClip;

        ui::Button  * fastbtn;//BaseNode * fastbtned;
        //public var sell : MovieClip;
        dragonBones::DBCCArmatureNode * faster;


		WorldInterface_mc();
		bool init();
	};


}
#endif
