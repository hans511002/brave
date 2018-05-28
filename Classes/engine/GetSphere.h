﻿#ifndef GETSPHERE_H
#define GETSPHERE_H
#include "BaseNode.h"
#include "MainClass.h"
#include "base/mc.h"
#include "engine/towers/Tower.h"

namespace engine
{ 
    class World;
	struct Arrow_mc :public MovieClip
	{
		towers::Tower * myTower;
    inline Arrow_mc(): MovieClip("worldinterface/", "Arrow_mc", "Arrow_mc"),myTower(0){};
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
    };
    struct GetAll_mc :public MovieClip
    {
		ui::Text * numTXT;
        Sprite * cross; 
        inline GetAll_mc():MovieClip("worldinterface/", "GetAll_mc", "GetAll_mc")
        {
            numTXT=this->createText("numTXT");
            cross=(Sprite*)this->getArmature()->getSlot("cross")->getDisplay();
        };
    };
    struct RadiusSphere_mc :public MovieClip
    {
        MovieClipSub * cont;
        inline RadiusSphere_mc(string arm):MovieClip("worldinterface/", arm, "RadiusSphere_mc")
      	{
      		cont=this->createMovieClipSub("cont");
      	};
        
    };
    struct RadiusFire_mc :public RadiusSphere_mc
    {
       inline  RadiusFire_mc():RadiusSphere_mc("RadiusFire_mc"){};
    };
    struct RadiusIce_mc :public RadiusSphere_mc
    {
        inline RadiusIce_mc():RadiusSphere_mc("RadiusIce_mc"){};
    };
    struct RadiusStone_mc:public RadiusSphere_mc
    { 
        inline RadiusStone_mc():RadiusSphere_mc("RadiusStone_mc"){};
    };
    struct RadiusLevin_mc:public RadiusSphere_mc
    {
        inline RadiusLevin_mc():RadiusSphere_mc("RadiusLevin_mc"){};
    };
    struct RadiusGetAll_mc :public RadiusSphere_mc
    { 
        MovieClipSub * cont1;
        MovieClipSub * cont2;
        MovieClipSub * cont3; 
        inline RadiusGetAll_mc():RadiusSphere_mc("RadiusGetAll_mc")
        {
            cont1=this->createMovieClipSub("cont1");
            cont2=this->createMovieClipSub("cont2");
            cont3=this->createMovieClipSub("cont3");
        }; 
    }; 
    struct MoveSphere_mc :public MovieClip
    {
        MovieClip * cont;
        ui::Text * numTXT; 
        inline MoveSphere_mc(string arm):MovieClip("worldinterface/","MoveSphere_mc","MoveSphere_mc")
        {
            cont=new MovieClip("worldinterface/",arm,"GetSphere_mc");
            numTXT=this->createText("numTXT");
        }; 
    };
    struct MoveFire_mc :public MoveSphere_mc
    { 
        MoveFire_mc(); 
    };
    struct MoveIce_mc :public MoveSphere_mc
    { 
        MoveIce_mc(); 
    };
    struct MoveLevin_mc :public MoveSphere_mc
    { 
        MoveLevin_mc(); 
    };
    struct MoveStone_mc :public MoveSphere_mc
    { 
        MoveStone_mc(); 
    };
    
    class GetSphere :public BaseNode
    {
    public:
        int i, j;
        //public var tempObject:Object;
        //public var tempObject1:Object;
		GetSphere_mc *container;//public var container:MovieClip;
		MovieClip* radius;
        int counter;
        //public var owner:Object;
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
        Sprite *  towerArrow;//public var towerArrow:Arrow_mc;
        string type;
		MovieClip* containerChange;

        GetSphere(string param1 = "holder");

        bool init();

        void  update();

        void  mouseMoveHandler(cocos2d::Event* param1);

        void   mouseDownHandler(cocos2d::Event* param1);

        void mouseUpHandler(cocos2d::Event* param1);

        void retrieveGetSphereToArchive();

        void manage(string param1, string param2 = "");

        void retrieveGetSphere();

        void getSphereFromArchiveToTower();

        void monitor();

        void kill();

    };
}
#endif

