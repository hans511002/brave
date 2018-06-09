#ifndef ENGINE_CASTSPHERE_H
#define ENGINE_CASTSPHERE_H
#include "BaseHeaders.h"
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"
 

namespace engine
{
	class World;
	struct   CastFire_mc : public MovieClip
	{
        inline CastFire_mc():MovieClip("worldinterface/", "CastFire_mc", "CastFire_mc"){};
	}; 
	struct   CastIce_mc : public MovieClip
	{
        inline CastIce_mc():MovieClip("worldinterface/", "CastIce_mc", "CastIce_mc"){};
	};
	struct   CastStone_mc : public MovieClip
	{
	    inline CastStone_mc():MovieClip("worldinterface/", "CastStone_mc", "CastStone_mc"){};
	}; 
	struct   CastLevin_mc : public MovieClip
	{
        inline CastLevin_mc():MovieClip("worldinterface/", "CastLevin_mc", "CastLevin_mc"){};
	};
	struct   CastFireIce_mc : public MovieClip
	{
        inline CastFireIce_mc():MovieClip("worldinterface/", "CastFireIce_mc", "CastFireIce_mc"){};
	};
	struct   CastFireStone_mc : public MovieClip
	{
        inline CastFireStone_mc():MovieClip("worldinterface/", "CastFireStone_mc", "CastFireStone_mc"){};
	};
	struct   CastFireLevin_mc : public MovieClip
	{
        inline CastFireLevin_mc():MovieClip("worldinterface/", "CastFireLevin_mc", "CastFireLevin_mc"){};
	};
	struct   CastIceStone_mc : public MovieClip
	{
        inline CastIceStone_mc():MovieClip("worldinterface/", "CastIceStone_mc", "CastIceStone_mc"){};
	};
	struct   CastIceLevin_mc : public MovieClip
	{
        inline CastIceLevin_mc():MovieClip("worldinterface/", "CastIceLevin_mc", "CastIceLevin_mc"){};
	};
	struct   CastStoneLevin_mc : public MovieClip
	{
        inline CastStoneLevin_mc():MovieClip("worldinterface/", "CastStoneLevin_mc", "CastStoneLevin_mc"){};
	};
	struct   CastGetAllLittle_mc : public MovieClip
	{
	    inline CastGetAllLittle_mc():MovieClip("worldinterface/", "CastGetAllLittle_mc", "CastGetAllLittle_mc"){};
	}; 
	struct   CastGetAll_mc : public MovieClip
	{
		MovieClipSub * haze1;
		MovieClipSub * haze2 ;
		MovieClipSub * haze3 ;
		MovieClipSub * haze4 ;
		MovieClipSub * haze5 ;
		MovieClipSub * haze6 ;
		MovieClipSub * haze7 ;
		MovieClipSub * haze8 ;
		MovieClipSub * haze9 ;
	    inline CastGetAll_mc():MovieClip("worldinterface/", "CastGetAll_mc", "CastGetAll_mc")
	    {
            haze1 = this->createMovieClipSub("haze1");
            haze2 = this->createMovieClipSub("haze2");
            haze3 = this->createMovieClipSub("haze3");
            haze4 = this->createMovieClipSub("haze4");
            haze5 = this->createMovieClipSub("haze5");
            haze6 = this->createMovieClipSub("haze6");
            haze7 = this->createMovieClipSub("haze7");
            haze8 = this->createMovieClipSub("haze8");
            haze9 = this->createMovieClipSub("haze9");
	    };
	};
	struct   CastGetAllSwamp_mc : public MovieClip
	{
		MovieClipSub * swamp1;
		MovieClipSub * swamp2;
		MovieClipSub * swamp3;
		MovieClipSub * swamp4;
		MovieClipSub * swamp5;
		inline CastGetAllSwamp_mc():MovieClip("worldinterface/", "CastGetAllSwamp_mc", "CastGetAllSwamp_mc")
	    {
            swamp1 = this->createMovieClipSub("swamp1");
            swamp2 = this->createMovieClipSub("swamp2");
            swamp3 = this->createMovieClipSub("swamp3");
            swamp4 = this->createMovieClipSub("swamp4");
            swamp5 = this->createMovieClipSub("swamp5"); 
	    };
	};

	class CastSphere :public BaseNode
	{
		int i, j, n;
		//public var tempObject:Object;
		//public var tempObject1:Object;
		MovieClip* container;
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
		Common::Array<bool> getAllForm;
		bool dead;
		int liveCounter;
		cocos2d::Vec2  leftSmoke_pt; 
		cocos2d::Vec2  rightSmoke_pt;
		cocos2d::Vec2  upSmoke_pt;
		cocos2d::Vec2  downSmoke_pt;

		CastSphere();

		bool init();

		void update();

		void kill();

	};
}
#endif
