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

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void mouseMoveHandler(cocos2d::EventMouse *param1);

			virtual void mouseDownHandler(cocos2d::EventMouse *event);

			virtual  void mouseUpHandler(cocos2d::EventMouse *event);

			virtual void monitor();

			virtual void autoguidersButtons();

			virtual void fastBuyUltraManage();

			virtual int fastBuyUltraScan();

			virtual void hintPosition(int param1 = 1);

			virtual  void  closeMenu(bool param1 = false);

			virtual void kill();
			virtual void remove();

		};
    }
}
#endif
