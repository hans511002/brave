#ifndef ENGINE_TOWERS_BUILDTOWERMENU_H
#define ENGINE_TOWERS_BUILDTOWERMENU_H
#include "BaseHeaders.h"
#include "Tower.h"
 

namespace engine
{
    class World;
    namespace towers
    { 
        class BuildTowerMenu_mc : public MovieClip
        {
        public:
            BuildTowerMenu_mc();
            ~BuildTowerMenu_mc();
            CREATE_FUNC(BuildTowerMenu_mc);
            bool init();
            void setPrice(int pr);
            MovieClip * cont;
            Sprite * place;
            ui::Text * price;
        };

        class BuildTowerMenu :public BaseNode
        {
        public:
            int i;
            Tower * tempObject; //public var tempObject : Object;
            BuildTowerMenu_mc * container;// public var container : BuildTowerMenu_mc;
            bool dead;// : Boolean;
            bool closeFlag;// : Boolean;
            Sprite *  myPlace;// : MovieClip;
            World *world;// : World;

            BuildTowerMenu(Sprite *  param1);


            bool init();

            void update();

            void mouseMoveHandler(cocos2d::Event * event);

            void mouseDownHandler(cocos2d::Event * event);

            void mouseUpHandler(cocos2d::Event * event);

            void monitor();

            void closeMenu();

            void kill();
        }; 
    }
}
#endif

