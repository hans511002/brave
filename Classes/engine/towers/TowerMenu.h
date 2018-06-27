#ifndef ENGINE_TOWERS_TOWERMENU_H
#define ENGINE_TOWERS_TOWERMENU_H
#include "BaseHeaders.h"
#include "TowerMenu_mc.h"
#include "Tower.h" 


namespace engine
{
 
	namespace towers
	{
		class BaseTowerMenu :public BaseNode
		{
		public:
			Tower * myTower;
			bool dead;
			World * world;
			bool closeFlag;
			bool openFlag;// :Boolean = true;
			TowerRadius_mc * towerRadius;// : MovieClip;
			bool openFastBuyUltraFlag;
			bool closeFastBuyUltraFlag;
			bool readyFastBuyUltraFlag;
			int fastBuyPrice;
			bool fastBuyBlockCost;
			string fastBuyUltraFlag;// :String;
			cocos2d::Point autoguidesMouse_pt;//:Point;
			BaseNode* autoguidesObject;//:Object;
			cocos2d::Point autoguidesObject_pt;//:Point;
			float autoguidesObjectWidth;//:Number;
			float autoguidesObjectHeight;//:Number;  
			BaseTowerMenu();
			virtual inline void closeMenu(bool param1 = false){};
		};

		class TowerMenu :public BaseTowerMenu
		{
		public:
			int i, j;// var i : int;        public var j:int;
			//public var tempObject:Object;
			//public var tempObject1:Object;
			//public var tempObject2:Object;
			//public var tempObject3:Object;
			//public var tempObject4:Object;
			TowerMenu_mc * container;// : TowerMenu_mc;
			TowerRadius_mc *  towerRadius1;// :MovieClip;
			TowerBase_mc *  exampleUltraTower;// :MovieClip;
			bool openUltraSection;// :Boolean;
			TowerMenuHint_mc* hint;// : TowerMenuHint_mc;
			TowerMenuHint_mc* hint1;// : TowerMenuHint_mc;
			cocos2d::EventMouse *lastE;//public var lastE:MouseEvent;
			BaseNode * training_12;// :Training_12;

			TowerMenu_mc *container1;
			MovieClip * starsAnima;// : AnimUpgrade_mc;

			TowerMenu(Tower * param1);

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void mouseMoveHandler(cocos2d::EventMouse * param1);

			virtual void mouseDownHandler(cocos2d::EventMouse * event);

			virtual void mouseUpHandler(cocos2d::EventMouse * event);

			virtual void upgradeManage();

			virtual void monitor();

			virtual void spheresMonitor();

			virtual void exampleUltraManage(string param1);

			virtual void autoguidersButtons();

			virtual void hintManage(string param1, int param2 = 1, Node * param3 = NULL);

			virtual void hintPosition(int param1 = 1, Node* param2 = NULL);

			virtual void ultraUpgradeTower(string param1, bool param2 = false);

			virtual void fastBuyUltraManage();

			virtual int fastBuyUltraScan(string param1);

			virtual void closeMenu(bool param1 = false);

			virtual void kill();

		};
	}
}
#endif
