#ifndef GETSPHERE_H
#define GETSPHERE_H
#include "BaseNode.h"
#include "MainClass.h"
#include "engine/mc/mc.h"

namespace engine
{
    class World;
	struct Arrow_mc :public OnceMovieClip
	{

	};
    struct GetSphere_mc :public BaseNode{
		MovieClip * cont;
		MovieClip * sphere1;
		MovieClip * sphere2;
		MovieClip * sphere3;
		MovieClip * sphere4;
    };
    struct GetAll_mc :public BaseNode
    {
		ui::Text * numTXT;
        Node * cross;
        dragonBones::CCArmatureDisplay * cont;
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

