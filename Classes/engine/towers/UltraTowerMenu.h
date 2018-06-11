#ifndef ENGINE_TOWERS_ULTRATOWERMENU_H
#define ENGINE_TOWERS_ULTRATOWERMENU_H
#include "BaseHeaders.h"
 
#include "Tower.h"
#include "TowerMenu.h" 


namespace engine
{
 
    namespace towers
    {
      
        class UltraTowerMenu :public BaseTowerMenu
        {
        public:
            int i, j;
            //public var tempObject:Object;
            //public var tempObject1:Object;
            UltraTowerMenu_mc * container;// : UltraTowerMenu_mc;
            cocos2d::EventMouse * lastE;// : MouseEvent;
            float sellTax;//:Number = 0.4;
            UltraTowerMenuHint_mc* hint;//:UltraTowerMenuHint_mc;
           
            UltraTowerMenu(Tower *param1);

            bool init();

virtual             void update(float dt=0);

            void mouseMoveHandler(cocos2d::EventMouse *param1);

            void mouseDownHandler(cocos2d::EventMouse *event);

            void mouseUpHandler(cocos2d::EventMouse *event);

            void monitor();

            void autoguidersButtons();

            void fastBuyUltraManage();

            int fastBuyUltraScan();

            void hintPosition(int param1 = 1);

			virtual  void  closeMenu(bool param1 = false);
			 
            void kill();

        };
    }
}
#endif
