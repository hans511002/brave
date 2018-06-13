#include "TowerMenu_mc.h"
#include "engine/World.h"

namespace engine
{
	namespace towers
	{
		TowerMenuHint_mc::TowerMenuHint_mc() :MovieClip("tower/", "TowerMenuHint_mc", "TowerMenuHint_mc")
		{
			cont = this->createMovieClipSub("cont");
			contCont1 = cont->createMovieClipSub("cont1");
			//不复用
			//contCont1Sphere1 = contCont1->createMovieClipSub("sphere1");
			//contCont1Sphere2 = contCont1->createMovieClipSub("sphere2");

			//复用
			contCont1Sphere1 = contCont1->createMovieClip("sphere1", "worldinterface", "GetSphere_mc");
			contCont1Sphere2 = contCont1->createMovieClip("sphere2", "worldinterface", "GetSphere_mc");
			//nameTXT            = this     ->createText        ("nameTXT");
		};// end function
		TowerRadius_mc::TowerRadius_mc() :BaseSprite("tower/TowerRadius_mc.png"), myTower(NULL)
		{
		}
		TowerMenu_mc::TowerMenu_mc() : MovieClip("tower/", "TowerMenu_mc", "TowerMenu_mc"){
			btnGetAll = this->createMovieClipSub("btnGetAll");
			btnGetAllBtnGetAllCase = btnGetAll->createCase("btnGetAllCase");
			btnTowerUpgr1 = this->createMovieClipSub("btnTowerUpgr1");
			btnTowerUpgr1BtnTowerUpgrCase = btnTowerUpgr1->createCase("btnTowerUpgrCase");
			btnTowerUpgr1CostTXT = btnTowerUpgr1->createText("costTXT");
			btnTowerUpgr2 = this->createMovieClipSub("btnTowerUpgr2");
			btnTowerUpgr2BtnTowerUpgrCase = btnTowerUpgr2->createCase("btnTowerUpgrCase");
			btnTowerUpgr2CostTXT = btnTowerUpgr2->createText("costTXT");
			btnTowerUpgr3 = this->createMovieClipSub("btnTowerUpgr3");
			btnTowerUpgr3BtnTowerUpgrCase = btnTowerUpgr3->createCase("btnTowerUpgrCase");
			btnTowerUpgr3CostTXT = btnTowerUpgr3->createText("costTXT");
			btnTowerUpgr4 = this->createMovieClipSub("btnTowerUpgr4");
			btnTowerUpgr4BtnTowerUpgrCase = btnTowerUpgr4->createCase("btnTowerUpgrCase");
			btnTowerUpgr4CostTXT = btnTowerUpgr4->createText("costTXT");
			btnUpgradeMenu = this->createMovieClipSub("btnUpgradeMenu");
			btnUpgradeMenuBtnUpgradeMenuCase = btnUpgradeMenu->createCase("btnUpgradeMenuCase");
			btnUpgradeMenuBtnUpgradeMenuLOCKCase = btnUpgradeMenu->createCase("btnUpgradeMenuLOCKCase");
			btnUpgradeMenuCostTXT = btnUpgradeMenu->createText("costTXT");

			cont1 = this->createMovieClipSub("cont1 ");
			cont2 = this->createMovieClipSub("cont2 ");
			fastBuyUltraCont = this->createMovieClipSub("fastBuyUltraCont");
			fastBuyUltraContBtnFastBuyUltra = fastBuyUltraCont->createMovieClipSub("btnFastBuyUltra");
			fastBuyUltraContBtnFastBuyUltraCostTXT = fastBuyUltraContBtnFastBuyUltra->createText("costTXT");
			fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase = fastBuyUltraContBtnFastBuyUltra->createCase("fastBuyUltraCase");
			fastBuyUltraContIndicator1 = fastBuyUltraCont->createMovieClipSub("indicator1");
			fastBuyUltraContIndicator2 = fastBuyUltraCont->createMovieClipSub("indicator2");
			fastBuyUltraContIndicator3 = fastBuyUltraCont->createMovieClipSub("indicator3");
			fastBuyUltraContIndicator4 = fastBuyUltraCont->createMovieClipSub("indicator4");


			sphereSlot1 = this->createMovieClipSub("sphereSlot1");
			sphereSlot1SphereSlotCase = sphereSlot1->createCase("sphereSlotCase");
			sphereSlot1SphereAnima = sphereSlot1->createMovieClip("sphereAnima", "tower/", "TowerMenuSphere_mc", "TowerMenuSphere_mc");
			sphereSlot1SphereAnimaCont = sphereSlot1SphereAnima->createMovieClipSub("cont");
			sphereSlot2 = this->createMovieClipSub("sphereSlot2");
			sphereSlot2SphereSlotCase = sphereSlot2->createCase("sphereSlotCase");
			sphereSlot2SphereAnima = sphereSlot2->createMovieClip("sphereAnima", "tower/", "TowerMenuSphere_mc", "TowerMenuSphere_mc");
			sphereSlot2SphereAnimaCont = sphereSlot2SphereAnima->createMovieClipSub("cont");
			sphereSlot3 = this->createMovieClipSub("sphereSlot3");
			sphereSlot3SphereSlotCase = sphereSlot3->createCase("sphereSlotCase");
			sphereSlot3SphereAnima = sphereSlot3->createMovieClip("sphereAnima", "tower/", "TowerMenuSphere_mc", "TowerMenuSphere_mc");
			sphereSlot3SphereAnimaCont = sphereSlot3SphereAnima->createMovieClipSub("cont");
			sphereSlot4 = this->createMovieClipSub("sphereSlot4");
			sphereSlot4SphereSlotCase = sphereSlot4->createCase("sphereSlotCase");

			sphereSlot4SphereAnima = sphereSlot4->createMovieClip("sphereAnima", "tower/", "TowerMenuSphere_mc", "TowerMenuSphere_mc");
			sphereSlot4SphereAnimaCont = sphereSlot4SphereAnima->createMovieClipSub("cont");

		}

		UltraTowerMenu_mc::UltraTowerMenu_mc() :MovieClip("tower/", "UltraTowerMenu_mc", "UltraTowerMenu_mc")
		{
			btnUpgradeMenu = this->createMovieClipSub("btnUpgradeMenu");
			btnUpgradeMenuBtnUpgradeMenuCase = btnUpgradeMenu->createCase("btnUpgradeMenuCase");
			btnUpgradeMenuCostTXT = btnUpgradeMenu->createText("costTXT");
			cont1 = this->createMovieClipSub("cont1");
			fastBuyUltraCont = this->createMovieClipSub("fastBuyUltraCont");
			fastBuyUltraContBtnFastBuyUltra = fastBuyUltraCont->createMovieClipSub("btnFastBuyUltra");
			fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase = fastBuyUltraContBtnFastBuyUltra->createCase("fastBuyUltraCase");
			fastBuyUltraContBtnFastBuyUltraIndicator1 = fastBuyUltraContBtnFastBuyUltra->createMovieClipSub("indicator1");
			fastBuyUltraContBtnFastBuyUltraIndicator2 = fastBuyUltraContBtnFastBuyUltra->createMovieClipSub("indicator2");
			fastBuyUltraContBtnFastBuyUltraIndicator3 = fastBuyUltraContBtnFastBuyUltra->createMovieClipSub("indicator3");
			fastBuyUltraContBtnFastBuyUltraIndicator4 = fastBuyUltraContBtnFastBuyUltra->createMovieClipSub("indicator4");
			fastBuyUltraContBtnFastBuyUltraCostTXT = fastBuyUltraContBtnFastBuyUltra->createText("costTXT");
			sellUltraTower = this->createMovieClipSub("sellUltraTower");
			sellUltraTowerSellUltraTowerCase = sellUltraTower->createCase("sellUltraTowerCase");

			sphereSlot1 = this->createMovieClipSub("sphereSlot1");
			sphereSlot1SphereSlotCase = sphereSlot1->createCase("sphereSlotCase");
			sphereSlot1SphereAnima = sphereSlot1->createMovieClip("sphereAnima", "tower/", "TowerMenuSphere_mc", "TowerMenuSphere_mc");
			sphereSlot1SphereAnimaCont = sphereSlot1SphereAnima->createMovieClipSub("cont");
			
			sphereSlot1 = this->createMovieClipSub("sphereSlot2");
			sphereSlot2SphereAnima = sphereSlot1->createMovieClip("sphereAnima", "tower/", "TowerMenuSphere_mc", "TowerMenuSphere_mc");
			sphereSlot2SphereAnimaCont = sphereSlot1SphereAnima->createMovieClipSub("cont");
			sphereSlot2SphereSlotCase = sphereSlot2->createCase("sphereSlotCase");


			//sphereSlot1SphereAnima= sphereSlot1->createMovieClipSub("sphereAnima");
			//sphereSlot1SphereAnimaFire= sphereSlot1SphereAnima->createMovieClipSub("fire");
			//sphereSlot1SphereAnimaIce= sphereSlot1SphereAnima->createMovieClipSub("ice");
			//sphereSlot1SphereAnimaStone= sphereSlot1SphereAnima->createMovieClipSub("stone");
			//sphereSlot1SphereAnimaLevin= sphereSlot1SphereAnima->createMovieClipSub("levin");
			//sphereSlot2= this->createMovieClipSub("sphereSlot2");
			//sphereSlot2SphereAnima= sphereSlot2->createMovieClipSub("sphereAnima");
			//sphereSlot2SphereAnimaFire= sphereSlot2SphereAnima->createMovieClipSub("fire");
			//sphereSlot2SphereAnimaIce= sphereSlot2SphereAnima->createMovieClipSub("ice");
			//sphereSlot2SphereAnimaStone= sphereSlot2SphereAnima->createMovieClipSub("stone");
			//sphereSlot2SphereAnimaLevin= sphereSlot2SphereAnima->createMovieClipSub("levin");

		}
		UltraTowerMenuHint_mc::UltraTowerMenuHint_mc() :MovieClip("tower/", "UltraTowerMenuHint_mc", "UltraTowerMenuHint_mc")
		{
			damageTXT = this->createText("damageTXT");
			nameTXT = this->createText("nameTXT");
			noteTXT = this->createText("noteTXT");

		}
	}
}
