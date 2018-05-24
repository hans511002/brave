#ifndef GETSPHERE_H
#define GETSPHERE_H
#include "BaseNode.h"
#include "MainClass.h"
#include "engine/mc/mc.h"

namespace engine
{ 
    class World;
	struct Arrow_mc :public MovieClip
	{
        MovieClip * myTower;
	};
    struct GetSphere_mc :public MovieClip{
		MovieClip * cont;
		MovieClip * sphere1;
		MovieClip * sphere2;
		MovieClip * sphere3;
		MovieClip * sphere4;
    };
    struct GetAll_mc :public MovieClip
    {
		ui::Text * numTXT;
        MovieClip * cross; 
    };
    struct RadiusSphere_mc :public MovieClip
    {
        MovieClip* cont;
        RadiusSphere_mc();
    };
    struct RadiusFire_mc :public RadiusSphere_mc
    {
        MovieClip* cont;
        RadiusFire_mc();
    };
    struct RadiusIce_mc :public RadiusSphere_mc
    {
        MovieClip* cont;
        RadiusIce_mc();
    };
    struct RadiusStone_mc:public RadiusSphere_mc
    {
        MovieClip* cont;
        RadiusStone_mc();
    };
    struct RadiusLevin_mc:public RadiusSphere_mc
    {
        MovieClip* cont;
        RadiusLevin_mc();
    };
    struct RadiusGetAll_mc :public RadiusSphere_mc
    { 
        MovieClip * cont1;
        MovieClip * cont2;
        MovieClip * cont3; 
        RadiusGetAll_mc(); 
    }; 
    struct MoveSphere_mc :public MovieClip
    {
        MovieClip * cont;
        ui::Text * numTXT; 
        MoveSphere_mc(); 
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
		BaseNode *container;//public var container:MovieClip;
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

