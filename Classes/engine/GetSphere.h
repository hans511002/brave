#ifndef GETSPHERE_H
#define GETSPHERE_H
#include "BaseHeaders.h"
#include "MainClass.h"
#include "base/mc.h"
#include "engine/towers/Tower.h"

namespace engine
{

	struct Arrow_mc :public MovieClip
	{
		towers::Tower * myTower;
		inline Arrow_mc() : MovieClip("worldinterface/", "Arrow_mc", "Arrow_mc"), myTower(0){
			SET_NODETYPENAME();
			const dragonBones::Rectangle & aabb = this->getArmature()->getArmatureData()->aabb;
			this->setContentSize(Size(aabb.width,aabb.height));
		};
	};
	struct GetSphere_mc :public MovieClip{
		MovieClipSub * cont;
		MovieClipSub * sphere1;
		MovieClipSub * sphere1Cont;
		MovieClipSub * sphere2;
		MovieClipSub * sphere2Cont;
		MovieClipSub * sphere3;
		MovieClipSub * sphere3Cont;
		MovieClipSub * sphere4;
		MovieClipSub * sphere4Cont;
		GetSphere_mc();
	};
	struct GetAll_mc :public MovieClip
	{
		ui::Text * numTXT;
		Sprite * cross;
		inline GetAll_mc() :MovieClip("worldinterface/", "GetAll_mc", "GetAll_mc")
		{
			SET_NODETYPENAME();
			numTXT = this->createText("numTXT");
			cross = (Sprite*)this->getArmature()->getSlot("cross")->getDisplay();
		};
	};
	struct RadiusSphere_mc :public MovieClip
	{
		MovieClipSub * cont1;
		MovieClipSub * cont2;
		MovieClipSub * cont3;
		MovieClipSub * cont;
		inline RadiusSphere_mc(string arm) :MovieClip("worldinterface/", arm, "RadiusSphere_mc"), cont1(0), cont2(0), cont3(0)
		{
			cont = this->createMovieClipSub("cont");
		};

	};
	struct RadiusFire_mc :public RadiusSphere_mc
	{
		inline  RadiusFire_mc() :RadiusSphere_mc("RadiusFire_mc"){
			SET_NODETYPENAME();
		};
	};
	struct RadiusIce_mc :public RadiusSphere_mc
	{
		inline RadiusIce_mc() :RadiusSphere_mc("RadiusIce_mc"){
			SET_NODETYPENAME();
		};
	};
	struct RadiusStone_mc :public RadiusSphere_mc
	{
		inline RadiusStone_mc() :RadiusSphere_mc("RadiusStone_mc"){
			SET_NODETYPENAME();
		};
	};
	struct RadiusLevin_mc :public RadiusSphere_mc
	{
		inline RadiusLevin_mc() :RadiusSphere_mc("RadiusLevin_mc"){
			SET_NODETYPENAME();
		};
	};
	struct RadiusGetAll_mc :public RadiusSphere_mc
	{
		//MovieClipSub * cont1;
		//MovieClipSub * cont2;
		//MovieClipSub * cont3; 
		inline RadiusGetAll_mc() :RadiusSphere_mc("RadiusGetAll_mc")
		{
			SET_NODETYPENAME();
			cont1 = this->createMovieClipSub("cont1");
			cont2 = this->createMovieClipSub("cont2");
			cont3 = this->createMovieClipSub("cont3");
		};
	};
	struct MoveSphere_mc :public MovieClip
	{
		MovieClip * cont;
		MCText * numTXT;
		inline MoveSphere_mc(string arm) :MovieClip("worldinterface/", "MoveSphere_mc", "MoveSphere_mc")
		{
			cont = new MovieClip("worldinterface/", arm, "GetSphere_mc");
			numTXT = this->createText("numTXT");
			this->addChild(cont);
		};
	};
	struct MoveFire_mc :public MoveSphere_mc
	{
		inline MoveFire_mc() :MoveSphere_mc("fire"){
			SET_NODETYPENAME();
		};
	};
	struct MoveIce_mc :public MoveSphere_mc
	{
		inline MoveIce_mc() :MoveSphere_mc("ice"){
			SET_NODETYPENAME();
		};
	};
	struct MoveStone_mc :public MoveSphere_mc
	{
		inline MoveStone_mc() :MoveSphere_mc("stone"){
			SET_NODETYPENAME();
		};
	};
	struct MoveLevin_mc :public MoveSphere_mc
	{
		inline MoveLevin_mc() :MoveSphere_mc("levin"){
			SET_NODETYPENAME();
		};
	};

	class GetSphere :public BaseNode
	{
	public:
		int i, j;
		//public var tempObject:Object;
		//public var tempObject1:Object;
		MovieClip *container;//public var container:MovieClip;
		RadiusSphere_mc* radius;
		int counter;
		void * owner; //public var owner:Object;
		string ownerType;
		cocos2d::Point ownerPoint;
		float myRadius;
		float myDamage;// = 0;
		int fireCount;
		int iceCount;
		int stoneCount;
		int levinCount;
		int getAllCount;
		Common::Array<string>   listOfStack;// Array;
		World * world;
		bool dead;
		int speedFrame;
		float speedX, speedY;

		Arrow_mc *  arrow;//public var arrow:Arrow_mc;
		Arrow_mc *  towerArrow;//public var towerArrow:Arrow_mc;
		string type;
		MovieClip* containerChange;

		GetSphere(string param1 = "holder");

		virtual bool init();

		virtual void  update(float dt = 0);

		virtual void  mouseMoveHandler(cocos2d::Event* param1);

		virtual void   mouseDownHandler(cocos2d::Event* param1);

		virtual void mouseUpHandler(cocos2d::Event* param1);

		virtual void retrieveGetSphereToArchive();

		virtual void manage(string param1, string param2 = "");

		virtual void retrieveGetSphere();

		virtual void getSphereFromArchiveToTower();

		virtual void monitor();

		virtual void kill();

	};
}
#endif

