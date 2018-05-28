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
            MovieClipSub * contCont1Sphere1    ;
            MovieClipSub * contCont1Sphere2    ;
            ui::Text     * nameTXT             ;
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


        class TowerMenu_mc :public BaseNode
        {
        public:
            MovieClipSub * btnGetAll                                                   ;
            MovieClipSub * btnTowerUpgr1                                               ;
            ui::Text     * btnTowerUpgr1CostTXT                                        ;
            MovieClipSub * btnTowerUpgr2                                               ;
            ui::Text     * btnTowerUpgr2CostTXT                                        ;
            MovieClipSub * btnTowerUpgr3                                               ;
            ui::Text     * btnTowerUpgr3CostTXT                                        ;
            MovieClipSub * btnTowerUpgr4                                               ;
            ui::Text     * btnTowerUpgr4CostTXT                                        ;
            MovieClipSub * btnUpgradeMenu                                              ;
			MCCase * btnUpgradeMenuBtnUpgradeMenuCase;
            MovieClipSub * cont1                                                       ;
            MovieClipSub * cont2                                                       ;
            MovieClipSub * fastBuyUltraCont                                            ;
            MovieClipSub * fastBuyUltraContBtnFastBuyUltra                             ;
            ui::Text     * fastBuyUltraContBtnFastBuyUltraCostTXT                      ;
			MCCase     * fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase;
            MovieClipSub * sphereSlot1                                                 ;
            MovieClipSub * sphereSlot1SphereAnima                                      ;
            MovieClipSub * sphereSlot1SphereAnimaFire                                  ;
            MovieClipSub * sphereSlot1SphereAnimaIce                                   ;
            MovieClipSub * sphereSlot1SphereAnimaStone                                 ;
            MovieClipSub * sphereSlot1SphereAnimaLevin                                 ;
            MovieClipSub * sphereSlot2                                                 ;
            MovieClipSub * sphereSlot2Fire                                             ;
            MovieClipSub * sphereSlot2Ice                                              ;
            MovieClipSub * sphereSlot2Stone                                            ;
            MovieClipSub * sphereSlot2Levin                                            ;
            MovieClipSub * sphereSlot3                                                 ;
            MovieClipSub * sphereSlot3Fire                                             ;
            MovieClipSub * sphereSlot3Ice                                              ;
            MovieClipSub * sphereSlot3Stone                                            ;
            MovieClipSub * sphereSlot3Levin                                            ;
            MovieClipSub * sphereSlot4                                                 ;
            MovieClipSub * sphereSlot4Fire                                             ;
            MovieClipSub * sphereSlot4Ice                                              ;
            MovieClipSub * sphereSlot4Stone                                            ;
            MovieClipSub * sphereSlot4Levin                                            ;


            CREATE_FUNC(TowerMenu_mc);

            TowerMenu_mc()
            {
                return;
            }// end function
        };

        class UltraTowerMenu_mc :public BaseNode
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

