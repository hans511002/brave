#ifndef GETSPHERE_H
#define GETSPHERE_H
#include "BaseNode.h"
#include "World.h"
#include "MainClass.h"

namespace engine
{
    class GetSphere_mc :public BaseNode{
        cocos2d::Node* cont;
        cocos2d::Node* sphere1;
        cocos2d::Node* sphere2;
        cocos2d::Node* sphere3;
        cocos2d::Node* sphere4;
    };
    class GetSphere :public BaseNode
    {
    public:
        int i ,j;
        //public var tempObject:Object;
        //public var tempObject1:Object;
        GetSphere_mc *container;//public var container:MovieClip;
        //public var radius:MovieClip;
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
        Common::Array<>   listOfStack;// Array;
        World * world ;
        bool dead;
        int speedFrame;
        float speedX, speedY; 

        //public var arrow:Arrow_mc;
        //public var towerArrow:Arrow_mc;
        string type;
        //public var containerChange:MovieClip;

            GetSphere(string param1= "holder");

        bool init();

        void  update() ;

        void  mouseMoveHandler(param1);

        void   mouseDownHandler(param1);

        void mouseUpHandler(param1) ;

        void retrieveGetSphereToArchive() ;

        void manage(string param1,string param2 = "") ;

        void retrieveGetSphere() ;

        void getSphereFromArchiveToTower() ;

        void monitor();

        void kill() ;  

    }
}
#endif

