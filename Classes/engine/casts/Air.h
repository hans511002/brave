#ifndef ENGINE_CASTS_AIR_H
#define ENGINE_CASTS_AIR_H
#include "BaseHeaders.h"

namespace engine
{
 
	namespace casts
	{
		struct Air_mc :public MovieClip
		{
			string direction;
			MovieClipSub* cont;//public var cont:MovieClip;
			MovieClipSub* contBlowing;
			MovieClipSub* dust1;//public var dust1:MovieClip;
			MovieClipSub* dust2;

			Air_mc();

		};
		struct MoveAir_mc :public MovieClip
		{
			MovieClipSub * down;
			MovieClipSub * left;
			MovieClipSub * right;
			MovieClipSub * up;
			MoveAir_mc();
		};
		class Air :public BaseNode
		{
		public:
			int i, j;
			//        public var tempObject:Object;
			//        public var tempObject1:Object;
			Air_mc * container;
			cocos2d::Point this_pt;
			cocos2d::Point  enemy_pt;
			World *world;
			string direction;//= "none";
			float radius;//:Number;
			bool dead;//:Boolean;
			bool openFlag;//:Boolean = true;
			int openCounter;//:int = 0;
			bool workFlag;//:Boolean;
			int liveCounter;//:int;
			int voiceCounter;//:int = 10;
			cocos2d::Point shoot_pt;//:Point;
			int cameraJitterTimer;//:int = 5;
			int cameraJitterCounter;//:int;
			float cameraXOffset;//:Number;
			float cameraYOffset;//:Number;

			Vec2 movePos;
		
			Air(cocos2d::Point param1, string param2 = "none");

			virtual bool init();

			virtual void update(float dt = 0);
			virtual void scan();
			virtual void attack();
			virtual void kill();
			virtual void remove();
		};
	}
}
#endif
