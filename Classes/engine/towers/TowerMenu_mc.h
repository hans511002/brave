#ifndef ENGINE_TOWERS_TOWERMENU_MC_H
#define ENGINE_TOWERS_TOWERMENU_MC_H
#include "BaseHeaders.h"
 
namespace engine
{
    namespace towers
    {
        class TowerMenuHint_mc :public MovieClip
        {
        public:
            MovieClipSub * cont                ;
            MovieClipSub * contCont1           ;
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
        
        struct BtnUpgradeMenu : public BaseSprite
        {
            ui::Text * costTXT;// : TextField;
            CREATE_FUNC(BtnUpgradeMenu);
            BtnUpgradeMenu();
            void setImage(int index);
        };

        struct SphereSlot : public BaseSprite
        {
            int currentFrame;
            dragonBones::CCArmatureDisplay * fire;
            dragonBones::CCArmatureDisplay * ice;
            dragonBones::CCArmatureDisplay * stone;
            dragonBones::CCArmatureDisplay * levin;
            CREATE_FUNC(SphereSlot);
            SphereSlot();
            void setImage(int type);
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
			MovieClipSub * cont1;
			MovieClipSub * cont2;
			MovieClipSub * fastBuyUltraCont;
			MovieClipSub * fastBuyUltraContBtnFastBuyUltra;
			MCText * fastBuyUltraContBtnFastBuyUltraCostTXT;
			MCCase * fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase;
			MovieClipSub * sphereSlot1;
			MovieClipSub * sphereSlot1SphereSlotCase;
			MovieClip * sphereSlot1SphereAnima;
			MovieClipSub * sphereSlot1SphereAnimaCont;
			MovieClipSub * sphereSlot2;
			MovieClipSub * sphereSlot2SphereSlotCase;
			MovieClip * sphereSlot2SphereAnima;
			MovieClipSub * sphereSlot2SphereAnimaCont;
			MovieClipSub * sphereSlot3;
			MovieClipSub * sphereSlot3SphereSlotCase;
			MovieClip * sphereSlot3SphereAnima;
			MovieClipSub * sphereSlot3SphereAnimaCont;
			MovieClipSub * sphereSlot4;
			MovieClipSub * sphereSlot4SphereSlotCase;
			MovieClip * sphereSlot4SphereAnima;
			MovieClipSub * sphereSlot4SphereAnimaCont;


			 

            TowerMenu_mc()
            {
                return;
            }// end function
        };

		class UltraTowerMenu_mc :public MovieClip
        {
		public:
            BtnUpgradeMenu * btnUpgradeMenu;// : MovieClip;
            MovieClip * cont1;// : MovieClip;
            BaseNode fastBuyUltraCont;// : MovieClip;
            BaseNode* sellUltraTower;// : MovieClip;
            BaseNode* sphereSlot1;//: MovieClip;
            BaseNode* sphereSlot2;// : MovieClip;
            CREATE_FUNC(UltraTowerMenu_mc);
             
            UltraTowerMenu_mc()
            {
                return;
            };// end function

        };
          class UltraTowerMenuHint_mc :public MovieClip
        {
        public:               
            ui::Text * damageTXT;
            ui::Text * nameTXT;
            ui::Text * noteTXT;
            CREATE_FUNC(UltraTowerMenuHint_mc);
            UltraTowerMenuHint_mc()
            {
                return;
            };// end function 
        };
    }
}

#endif

