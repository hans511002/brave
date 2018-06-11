#ifndef ENGINE_CASTSPHERE_H
#define ENGINE_CASTSPHERE_H
#include "BaseHeaders.h"
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"
 

namespace engine
{
 
	struct CastSphereBase_mc :public MovieClip
	{
		int myCounter;
		inline CastSphereBase_mc(string root, string arm, string dbname) :MovieClip(root, arm, dbname), myCounter(0){};
	};

	struct   CastFire_mc : public CastSphereBase_mc
	{
		inline CastFire_mc() :CastSphereBase_mc("worldinterface/", "CastFire_mc", "CastFire_mc"){};
	}; 
	struct   CastIce_mc : public CastSphereBase_mc
	{
		inline CastIce_mc() :CastSphereBase_mc("worldinterface/", "CastIce_mc", "CastIce_mc"){};
	};
	struct   CastStone_mc : public CastSphereBase_mc
	{
		inline CastStone_mc() :CastSphereBase_mc("worldinterface/", "CastStone_mc", "CastStone_mc"){};
	}; 
	struct   CastLevin_mc : public CastSphereBase_mc
	{
		inline CastLevin_mc() :CastSphereBase_mc("worldinterface/", "CastLevin_mc", "CastLevin_mc"){};
	};
	struct   CastFireIce_mc : public CastSphereBase_mc
	{
		inline CastFireIce_mc() :CastSphereBase_mc("worldinterface/", "CastFireIce_mc", "CastFireIce_mc"){};
	};
	struct   CastFireStone_mc : public CastSphereBase_mc
	{
		inline CastFireStone_mc() :CastSphereBase_mc("worldinterface/", "CastFireStone_mc", "CastFireStone_mc"){};
	};
	struct   CastFireLevin_mc : public CastSphereBase_mc
	{
		inline CastFireLevin_mc() :CastSphereBase_mc("worldinterface/", "CastFireLevin_mc", "CastFireLevin_mc"){};
	};
	struct   CastIceStone_mc : public CastSphereBase_mc
	{
		inline CastIceStone_mc() :CastSphereBase_mc("worldinterface/", "CastIceStone_mc", "CastIceStone_mc"){};
	};
	struct   CastIceLevin_mc : public CastSphereBase_mc
	{
		inline CastIceLevin_mc() :CastSphereBase_mc("worldinterface/", "CastIceLevin_mc", "CastIceLevin_mc"){};
	};
	struct   CastStoneLevin_mc : public CastSphereBase_mc
	{
		inline CastStoneLevin_mc() :CastSphereBase_mc("worldinterface/", "CastStoneLevin_mc", "CastStoneLevin_mc"){};
	};
	struct   CastGetAllLittle_mc : public CastSphereBase_mc
	{
		inline CastGetAllLittle_mc() :CastSphereBase_mc("worldinterface/", "CastGetAllLittle_mc", "CastGetAllLittle_mc"){};
	}; 
	struct MovieClipSubMyFrame :public MovieClipSub
	{
		inline MovieClipSubMyFrame(MC *mc, string solt) :MovieClipSub(mc, slot){};
		int myFrame;
		Vec2 myPoint;
	};
	struct   CastGetAll_mc : public CastSphereBase_mc
	{
		MovieClipSubMyFrame * haze1;
		MovieClipSubMyFrame * haze2;
		MovieClipSubMyFrame * haze3;
		MovieClipSubMyFrame * haze4;
		MovieClipSubMyFrame * haze5;
		MovieClipSubMyFrame * haze6;
		MovieClipSubMyFrame * haze7;
		MovieClipSubMyFrame * haze8;
		MovieClipSubMyFrame * haze9;
		inline CastGetAll_mc() :CastSphereBase_mc("worldinterface/", "CastGetAll_mc", "CastGetAll_mc")
	    {
			haze1 = new MovieClipSubMyFrame(this, "haze1");
			haze2 = new MovieClipSubMyFrame(this, "haze2");
			haze3 = new MovieClipSubMyFrame(this, "haze3");
			haze4 = new MovieClipSubMyFrame(this, "haze4");
			haze5 = new MovieClipSubMyFrame(this, "haze5");
			haze6 = new MovieClipSubMyFrame(this, "haze6");
			haze7 = new MovieClipSubMyFrame(this, "haze7");
			haze8 = new MovieClipSubMyFrame(this, "haze8");
			haze9 = new MovieClipSubMyFrame(this, "haze9");
			//haze1 = this->createMovieClipSub("haze1");
            //haze2 = this->createMovieClipSub("haze2");
            //haze3 = this->createMovieClipSub("haze3");
            //haze4 = this->createMovieClipSub("haze4");
            //haze5 = this->createMovieClipSub("haze5");
            //haze6 = this->createMovieClipSub("haze6");
            //haze7 = this->createMovieClipSub("haze7");
            //haze8 = this->createMovieClipSub("haze8");
            //haze9 = this->createMovieClipSub("haze9");
	    };
	};
	struct   CastGetAllSwamp_mc : public CastSphereBase_mc
	{
		MovieClipSubMyFrame * swamp1;
		MovieClipSubMyFrame * swamp2;
		MovieClipSubMyFrame * swamp3;
		MovieClipSubMyFrame * swamp4;
		MovieClipSubMyFrame * swamp5;
		inline CastGetAllSwamp_mc() :CastSphereBase_mc("worldinterface/", "CastGetAllSwamp_mc", "CastGetAllSwamp_mc")
	    {
            //swamp1 = this->createMovieClipSub("swamp1");
            //swamp2 = this->createMovieClipSub("swamp2");
            //swamp3 = this->createMovieClipSub("swamp3");
            //swamp4 = this->createMovieClipSub("swamp4");
            //swamp5 = this->createMovieClipSub("swamp5"); 
			swamp1 = new MovieClipSubMyFrame(this, "swamp1");
			swamp2 = new MovieClipSubMyFrame(this, "swamp2");
			swamp3 = new MovieClipSubMyFrame(this, "swamp3");
			swamp4 = new MovieClipSubMyFrame(this, "swamp4");
			swamp5 = new MovieClipSubMyFrame(this, "swamp5");
	    };
	};

	class CastSphere :public BaseNode
	{
	public:
		int i, j, n;
		//public var tempObject:Object;
		//public var tempObject1:Object;
		CastSphereBase_mc* container;
		string sphereType;
		int fireCount;
		int iceCount;
		int stoneCount;
		int levinCount;
		int getAllCount;
		cocos2d::Vec2 this_pt;
		World* world;
		float radius;
		CastGetAllSwamp_mc * additAnamation;
		Common::Array<int> getAllForm;
		bool dead;
		int liveCounter;
		cocos2d::Vec2  leftSmoke_pt; 
		cocos2d::Vec2  rightSmoke_pt;
		cocos2d::Vec2  upSmoke_pt;
		cocos2d::Vec2  downSmoke_pt;

		CastSphere();

		bool init();

		virtual void update(float dt=0);

		void kill();

	};
}
#endif
