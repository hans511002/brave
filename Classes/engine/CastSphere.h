#ifndef ENGINE_CASTSPHERE_H
#define ENGINE_CASTSPHERE_H
#include "BaseHeaders.h"
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"
#include "engine/mc/mc.h"

namespace engine
{
	class World;
	struct   CastFire_mc : public MovieClip
	{
        CastFire_mc();
	}; 
	struct   CastIce_mc : public MovieClip
	{

	};
	struct   CastStone_mc : public MovieClip
	{
	}; 
	struct   CastLevin_mc : public MovieClip
	{

	};
	struct   CastFireIce_mc : public MovieClip
	{

	};
	struct   CastFireStone_mc : public MovieClip
	{

	};
	struct   CastFireLevin_mc : public MovieClip
	{

	};
	struct   CastIceStone_mc : public MovieClip
	{

	};
	struct   CastIceLevin_mc : public MovieClip
	{

	};
	struct   CastStoneLevin_mc : public MovieClip
	{

	};
	struct   CastGetAllLittle_mc : public MovieClip
	{
	}; 
	struct   CastGetAll_mc : public MovieClip
	{
		MovieClip* haze1;
		MovieClip* haze2 ;
		MovieClip* haze3 ;
		MovieClip* haze4 ;
		MovieClip* haze5 ;
		MovieClip* haze6 ;
		MovieClip* haze7 ;
		MovieClip* haze8 ;
		MovieClip* haze9 ;
	};
	struct   CastGetAllSwamp_mc : public MovieClip
	{
		MovieClip * swamp1;
		MovieClip * swamp2;
		MovieClip * swamp3;
		MovieClip * swamp4;
		MovieClip * swamp5;
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
