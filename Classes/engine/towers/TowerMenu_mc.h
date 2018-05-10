#ifndef ENGINE_TOWERS_TOWERMENU_MC_H
#define ENGINE_TOWERS_TOWERMENU_MC_H
#include "BaseHeaders.h"
 
namespace engine
{
    namespace towers
    {
        class TowerMenuHint_mc :public BaseNode
        {
        public:
            MovieClip * cont;// : MovieClip;
            ui::Text * nameTXT;// : TextField;
            CREATE_FUNC(TowerMenuHint_mc);
            TowerMenuHint_mc()
            {
                return;
            };// end function
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
            ui::Button * btnGetAll;// : MovieClip;
            BaseSprite *  btnTowerUpgr1;// : MovieClip;
            BaseSprite*  btnTowerUpgr2;// : MovieClip;
            BaseSprite*  btnTowerUpgr3;// : MovieClip;
            BaseSprite*  btnTowerUpgr4;// : MovieClip;
            BtnUpgradeMenu*  btnUpgradeMenu;// : MovieClip;
            dragonBones::CCArmatureDisplay *  cont1;// : MovieClip;
            dragonBones::CCArmatureDisplay *  cont2;// : MovieClip;
            BaseNode*  fastBuyUltraCont;//: MovieClip;
            BaseNode* sphereSlot1;// : MovieClip;
            BaseNode* sphereSlot2;// : MovieClip;
            BaseNode* sphereSlot3;// : MovieClip;
            BaseNode* sphereSlot4;// : MovieClip;
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
            dragonBones::CCArmatureDisplay * cont1;// : MovieClip;
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
    }
}

#endif

