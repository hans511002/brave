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
			//contCont1Sphere1 = contCont1->createMovieClipSub("sphere1");
			//contCont1Sphere2 = contCont1->createMovieClipSub("sphere2");
			contCont1Sphere1 = new MovieClip(contCont1, "sphere1", "worldinterface", "GetSphere_mc");
			contCont1Sphere2 = new MovieClip(contCont1, "sphere1", "worldinterface", "GetSphere_mc");
			//nameTXT            = this     ->createText        ("nameTXT");
		};// end function
        TowerRadius_mc::TowerRadius_mc() :BaseSprite("Tower/TowerRadius_mc.png"), myTower(NULL)
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
			cont1 = this->createMovieClipSub("cont1 ");
			cont2 = this->createMovieClipSub("cont2 ");
			fastBuyUltraCont = this->createMovieClipSub("fastBuyUltraCont");
			fastBuyUltraContBtnFastBuyUltra = fastBuyUltraCont->createMovieClipSub("btnFastBuyUltra");
			fastBuyUltraContBtnFastBuyUltraCostTXT = fastBuyUltraContBtnFastBuyUltra->createText("costTXT");
			fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase = fastBuyUltraContBtnFastBuyUltra->createCase("fastBuyUltraCase");
			sphereSlot1 = this->createMovieClipSub("sphereSlot1");
			sphereSlot1SphereSlotCase = sphereSlot1->createMovieClipSub("sphereSlotCase");
			sphereSlot1SphereAnima = sphereSlot1->createMovieClip("sphereAnima", "worldinterface/", "sphere", "GetSphere_mc");
			sphereSlot1SphereAnimaCont = sphereSlot1SphereAnima->createMovieClipSub("cont");
			sphereSlot2 = this->createMovieClipSub("sphereSlot2");
			sphereSlot2SphereSlotCase = sphereSlot2->createMovieClipSub("sphereSlotCase");
			sphereSlot2SphereAnima = sphereSlot2->createMovieClip("sphereAnima", "worldinterface/", "sphere", "GetSphere_mc");
			sphereSlot2SphereAnimaCont = sphereSlot2SphereAnima->createMovieClipSub("cont");
			sphereSlot3 = this->createMovieClipSub("sphereSlot3");
			sphereSlot3SphereSlotCase = sphereSlot3->createMovieClipSub("sphereSlotCase");
			sphereSlot3SphereAnima = sphereSlot3->createMovieClip("sphereAnima", "worldinterface/", "sphere", "GetSphere_mc");
			sphereSlot3SphereAnimaCont = sphereSlot3SphereAnima->createMovieClipSub("cont");
			sphereSlot4 = this->createMovieClipSub("sphereSlot4");
			sphereSlot4SphereSlotCase = sphereSlot4->createMovieClipSub("sphereSlotCase");
			sphereSlot4SphereAnima = sphereSlot4->createMovieClip("sphereAnima", "worldinterface/", "sphere", "GetSphere_mc");
			sphereSlot4SphereAnimaCont = sphereSlot4SphereAnima->createMovieClipSub("cont");

		}
     
    }
}
 