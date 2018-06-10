#ifndef ENGINE_TOWERS_TOWERMENU_MC_H
#define ENGINE_TOWERS_TOWERMENU_MC_H
#include "BaseHeaders.h"

namespace engine
{
	namespace towers
	{
		class Tower;
		class TowerMenuHint_mc :public MovieClip
		{
		public:
			MovieClipSub * cont;
			MovieClipSub * contCont1;
			MovieClip * contCont1Sphere1;
			MovieClip * contCont1Sphere2;
			//ui::Text     * nameTXT             ;
			TowerMenuHint_mc();
		};

		class TowerRadius_mc :public BaseSprite{
		public:
			Tower * myTower;
			TowerRadius_mc();
		};

		class TowerMenu_mc :public MovieClip
		{
		public:
			MovieClipSub * btnGetAll;
			MCCase * btnGetAllBtnGetAllCase;
			MovieClipSub * btnTowerUpgr1;
			MCCase * btnTowerUpgr1BtnTowerUpgrCase;
			MCText * btnTowerUpgr1CostTXT;
			MovieClipSub * btnTowerUpgr2;
			MCCase * btnTowerUpgr2BtnTowerUpgrCase;
			MCText * btnTowerUpgr2CostTXT;
			MovieClipSub * btnTowerUpgr3;
			MCCase * btnTowerUpgr3BtnTowerUpgrCase;
			MCText * btnTowerUpgr3CostTXT;
			MovieClipSub * btnTowerUpgr4;
			MCCase * btnTowerUpgr4BtnTowerUpgrCase;
			MCText * btnTowerUpgr4CostTXT;
			MovieClipSub * btnUpgradeMenu;
			MCCase * btnUpgradeMenuBtnUpgradeMenuCase; 
			MCCase * btnUpgradeMenuBtnUpgradeMenuLOCKCase;
			MCText * btnUpgradeMenuCostTXT;

			MovieClipSub * cont1;
			MovieClipSub * cont2;
			MovieClipSub * fastBuyUltraCont;
			MovieClipSub * fastBuyUltraContBtnFastBuyUltra;
			MCText * fastBuyUltraContBtnFastBuyUltraCostTXT;
			MCCase * fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase;
			MovieClipSub * fastBuyUltraContIndicator1;
			MovieClipSub * fastBuyUltraContIndicator2;
			MovieClipSub * fastBuyUltraContIndicator3;
			MovieClipSub * fastBuyUltraContIndicator4; 

			MovieClipSub * sphereSlot1;
			MCCase * sphereSlot1SphereSlotCase;
			MovieClip * sphereSlot1SphereAnima;
			MovieClipSub * sphereSlot1SphereAnimaCont;
			MovieClipSub * sphereSlot2;
			MCCase * sphereSlot2SphereSlotCase;
			MovieClip * sphereSlot2SphereAnima;
			MovieClipSub * sphereSlot2SphereAnimaCont;
			MovieClipSub * sphereSlot3;
			MCCase * sphereSlot3SphereSlotCase;
			MovieClip * sphereSlot3SphereAnima;
			MovieClipSub * sphereSlot3SphereAnimaCont;
			MovieClipSub * sphereSlot4;
			MCCase * sphereSlot4SphereSlotCase;
			MovieClip * sphereSlot4SphereAnima;
			MovieClipSub * sphereSlot4SphereAnimaCont;

			TowerMenu_mc();
		};

		class UltraTowerMenu_mc :public MovieClip
		{
		public:

			MovieClipSub * btnUpgradeMenu;
			MCCase * btnUpgradeMenuBtnUpgradeMenuCase;
			MCText * btnUpgradeMenuCostTXT;
			MovieClipSub * cont1;
			MovieClipSub * fastBuyUltraCont;
			MovieClipSub * fastBuyUltraContBtnFastBuyUltra;
			MCCase * fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase;
			MovieClipSub * fastBuyUltraContBtnFastBuyUltraIndicator1;
			MovieClipSub * fastBuyUltraContBtnFastBuyUltraIndicator2;
			MovieClipSub * fastBuyUltraContBtnFastBuyUltraIndicator3;
			MovieClipSub * fastBuyUltraContBtnFastBuyUltraIndicator4;
			MCText * fastBuyUltraContBtnFastBuyUltraCostTXT;
			MovieClipSub * sellUltraTower;
			MCCase * sellUltraTowerSellUltraTowerCase;
			MovieClipSub * sphereSlot1;
			MovieClip  * sphereSlot1SphereAnima;
			MovieClipSub * sphereSlot1SphereAnimaCont;
			MovieClipSub * sphereSlot2;
			MovieClip * sphereSlot2SphereAnima;
			MovieClipSub * sphereSlot2SphereAnimaCont;



			UltraTowerMenu_mc();

		};
		class UltraTowerMenuHint_mc :public MovieClip
		{
		public:
			MCText * damageTXT;
			MCText * nameTXT;
			MCText * noteTXT;

			UltraTowerMenuHint_mc();
		};
	}
}

#endif

