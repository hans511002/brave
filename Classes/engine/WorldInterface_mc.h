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
			BaseSprite * barinfoback;
			BaseSprite * healthbar;
			BaseSprite * moneybar;

			//public var book : MovieClip;
			BaseNode * butCastAir;// : MovieClip;
			BaseNode * butCastGolem;// : MovieClip;
			BaseNode * butCastIceman;// : MovieClip;

			BaseSprite  * fastbtn;//BaseNode * fastbtned;
			//public var sell : MovieClip;
			dragonBones::DBCCArmatureNode * faster;//public var  : MovieClip; 


			BaseSprite  * buyFire;//: MovieClip;
			BaseSprite  * buyIce;// : MovieClip;
			BaseSprite  * buyLevin;//: MovieClip;
			BaseSprite  * buyStone;//: MovieClip;
			BaseSprite  * buyGetAll;//: MovieClip; 
			
			BaseSprite  * getAll;////public var getAll : MovieClip; allsphere
			  

			BaseSprite * pause;//public var pause : MovieClip;
			BaseSprite * startWaves;// public var startWaves : MovieClip;
			dragonBones::DBCCArmatureNode * stoneBacklight;//public var stoneBacklight : MovieClip;
			dragonBones::DBCCArmatureNode * levinBacklight;//public var levinBacklight : MovieClip;
			dragonBones::DBCCArmatureNode * iceBacklight;//public var iceBacklight : MovieClip;
			dragonBones::DBCCArmatureNode * fireBacklight;//public var fireBacklight : MovieClip;
			 
			BaseSprite * iceBack;//public var iceBack : MovieClip;
			BaseSprite * fireBack;//public var fireBack : MovieClip;
			BaseSprite * levinBack;//public var levinBack : MovieClip;
			BaseSprite * stoneBack;// : MovieClip;
			dragonBones::DBCCArmatureNode *iceSphere;//public var iceSphere : MovieClip;
			dragonBones::DBCCArmatureNode *fireSphere;//public var fireSphere : MovieClip;
			dragonBones::DBCCArmatureNode *levinSphere;//public var levinSphere : MovieClip;
			dragonBones::DBCCArmatureNode *stoneSphere;// stoneSphere public var stoneSphere : MovieClip;
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


			WorldInterface_mc(); 
			bool init(); 
		};

 
}
#endif
