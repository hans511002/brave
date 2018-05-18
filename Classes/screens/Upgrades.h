#ifndef SCREENS_UPGRADES_H
#define SCREENS_UPGRADES_H
#include "BaseHeaders.h"   

namespace engine
{
    class World;
}
using namespace engine;

namespace screens
{   
    struct Upgrades_mc : public MovieClip
    {
        public var back:MovieClip;
        public var cont:MovieClip;
        public var shadow:MovieClip;

        Upgrades_mc();

    };
    struct HintUpgrade_mc : public MovieClip
    {
        ui::Text* noteTXT;

        HintUpgrade_mc();

    };
    class Upgrades : public BaseNode
    {
    public:
        int i;
        //Object tempObject;
        //Object tempObject1;
        Upgrades_mc * container;
        int frameCounter;
        bool openFlag;
        bool closeFlag;
        LevelsMenu * levelsMenu;
        MovieClip * nowUpgradeButton;
        bool dead;
        HintUpgrade_mc hint;
        Common::Array<MovieClip *> listOfUpgradeAnima;
        int costGolemUpgrade1;
        int costGolemUpgrade2;
        int costGolemUpgrade3;
        int costGolemUpgrade4;
        int costGolemUpgrade5;
        int costIcemanUpgrade1;
        int costIcemanUpgrade2;
        int costIcemanUpgrade3;
        int costIcemanUpgrade4;
        int costIcemanUpgrade5;
        int costAirUpgrade1;
        int costAirUpgrade2;
        int costAirUpgrade3;
        int costAirUpgrade4;
        int costAirUpgrade5;
        int costFireUpgrade1;
        int costFireUpgrade2;
        int costFireUpgrade3;
        int costFireUpgrade4;
        int costFireUpgrade5;
        int costIceUpgrade1;
        int costIceUpgrade2;
        int costIceUpgrade3;
        int costIceUpgrade4;
        int costIceUpgrade5;
        int costStoneUpgrade1;
        int costStoneUpgrade2;
        int costStoneUpgrade3;
        int costStoneUpgrade4;
        int costStoneUpgrade5;
        int costLevinUpgrade1;
        int costLevinUpgrade2;
        int costLevinUpgrade3;
        int costLevinUpgrade4;
        int costLevinUpgrade5;

        Upgrades();

        bool init();

        void enterFrameHandler(cocos2d::Event * event);
        void mouseMoveHandler(cocos2d::Event * event);

        void mouseDownHandler(cocos2d::Event * event);

        void mouseUpHandler(cocos2d::Event * event);

        void upgradeUpdate();

        void manageListeners(string param1);

        void close();

        void kill();

        //void reInit(event:Event);

    }
}
#endif
