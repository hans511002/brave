#ifndef ENGINE_CASTS_AIR_H
#define ENGINE_CASTS_AIR_H
#include "BaseHeaders.h"

namespace engine
{
	class World;
	namespace casts
	{
		class Air_mc :public MovieClip
    	{
    	public:
    		string direction;
    		MovieClipSub* cont;//public var cont:MovieClip;
    		MovieClipSub* contBlowing;
    		MovieClipSub* dust1;//public var dust1:MovieClip;
    		MovieClipSub* dust2;
    		Air_mc(string dir);
    		void clear();
    		virtual void gotoAndStop(int cur)
    		{
    			MovieClip::gotoAndStop(cur);
    			this->clear();
    			this->cont = new MovieClipSub(this,this->getArmature()->getSlot("cont")->getChildArmature());
    			this->dust1 = new MovieClipSub(this, this->getArmature()->getSlot("dust1")->getChildArmature());
    			this->dust2 = new MovieClipSub(this, "dust2" );
    			dragonBones::Armature * arm = cont->getArmature()->getSlot("blowing")->getChildArmature();
    			this->contBlowing = new MovieClipSub(cont, arm);
    			this->cont->gotoAndStop(48);
    			this->dust1->stop();
    			this->dust2->stop();
    			this->dust1->arm->getBone("dust1")->setVisible(false);
    			this->dust2->arm->getBone("dust2")->setVisible(false);
    			this->cont->play(0);
    		};
    	};
		class MoveAir_mc :public MovieClip
		{
			MovieClip* down;//:MovieClip;
			MovieClip* left;//:MovieClip;
			MovieClip* right;//:MovieClip;
			MovieClip* up;//:MovieClip;
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

			Air(cocos2d::Point param1, string param2 = "none");

			bool init();

			void update();
			void scan();
			void attack();
			void kill();
		};
	}
}
#endif
