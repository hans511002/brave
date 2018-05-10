#ifndef ENGINE_TOWERS_ULTRATOWERMENU_H
#define ENGINE_TOWERS_ULTRATOWERMENU_H
#include "BaseHeaders.h"
 
#include "Tower.h"
#include "TowerMenu_mc.h" 


namespace engine
{
    class World;
    namespace towers
    {
        class UltraTowerMenuHint_mc :public BaseNode
        {
        public:
            Node * cont;// : MovieClip;
            ui::Text * nameTXT;// : TextField;
            CREATE_FUNC(UltraTowerMenuHint_mc);
            UltraTowerMenuHint_mc()
            {
                return;
            };// end function
        };
        class UltraTowerMenu :public BaseNode
        {
        public:
            int i, j;
            //public var tempObject:Object;
            //public var tempObject1:Object;
            UltraTowerMenu_mc * container;// : UltraTowerMenu_mc;
            Tower *myTower;
            bool dead;
            World *world;
            bool closeFlag;
            bool openFlag;//= true;
            TowerRadius_mc * towerRadius;//:MovieClip;
            cocos2d::EventMouse * lastE;// : MouseEvent;
            float sellTax;//:Number = 0.4;
            string fastBuyUltraFlag;//:String;
            bool openFastBuyUltraFlag;//:Boolean;
            bool closeFastBuyUltraFlag;//:Boolean;
            bool readyFastBuyUltraFlag;//:Boolean;
            int fastBuyPrice;//:int = 0;
            bool fastBuyBlockCost;//:Boolean;
            UltraTowerMenuHint_mc* hint;//:UltraTowerMenuHint_mc;
            cocos2d::Point autoguidesMouse_pt;//:Point;
            BaseNode* autoguidesObject;//:Object;
            cocos2d::Point autoguidesObject_pt;//:Point;
            float autoguidesObjectWidth;//:Number;
            float autoguidesObjectHeight;//:Number;

            UltraTowerMenu(Tower *param1);

            bool init();

            void update();

            void mouseMoveHandler(cocos2d::Event *param1);

            void mouseDownHandler(cocos2d::Event *event);

            void mouseUpHandler(cocos2d::Event *event);

            void monitor();

            void autoguidersButtons();

            void fastBuyUltraManage();

            int fastBuyUltraScan();

            void hintPosition(int param1 = 1);

            void closeMenu(bool param1 = false);
            void kill();

        };
    }
}
#endif
