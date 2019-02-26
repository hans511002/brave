#ifndef SCREENS_UPGRADES_H
#define SCREENS_UPGRADES_H
#include "BaseHeaders.h"   
#include "Screen.h"   

namespace screens
{

	struct UpgradeButton :public MovieClipSub
	{
		MCCase * upgradeCase;
		MCText * starsTXT;
		UpgradeButton(MC *mc, const std::string &  slot, const string &  defAniName = "");
	};
	struct Upgrades_mc : public MovieClip
	{
		MovieClip * stars;
		MCText * starsTXT;
		Back_mc * back;
		MovieClipSub* cont;
		MCCase * shadow;

		MovieClipSub* contBtnReset;
		MCCase* contBtnResetResetCase;
		MovieClipSub* contBtnAccept;
		MCCase* contBtnAcceptAcceptCase;
		UpgradeButton * levinUpgrade1;
		UpgradeButton * levinUpgrade2;
		UpgradeButton * levinUpgrade3;
		UpgradeButton * levinUpgrade4;
		UpgradeButton * levinUpgrade5;
		UpgradeButton * stoneUpgrade1;
		UpgradeButton * stoneUpgrade2;
		UpgradeButton * stoneUpgrade3;
		UpgradeButton * stoneUpgrade4;
		UpgradeButton * stoneUpgrade5;
		UpgradeButton * iceUpgrade1;
		UpgradeButton * iceUpgrade2;
		UpgradeButton * iceUpgrade3;
		UpgradeButton * iceUpgrade4;
		UpgradeButton * iceUpgrade5;
		UpgradeButton * fireUpgrade1;
		UpgradeButton * fireUpgrade2;
		UpgradeButton * fireUpgrade3;
		UpgradeButton * fireUpgrade4;
		UpgradeButton * fireUpgrade5;
		UpgradeButton * airUpgrade1;
		UpgradeButton * airUpgrade2;
		UpgradeButton * airUpgrade3;
		UpgradeButton * airUpgrade4;
		UpgradeButton * airUpgrade5;
		UpgradeButton * icemanUpgrade1;
		UpgradeButton * icemanUpgrade2;
		UpgradeButton * icemanUpgrade3;
		UpgradeButton * icemanUpgrade4;
		UpgradeButton * icemanUpgrade5;
		UpgradeButton * golemUpgrade1;
		UpgradeButton * golemUpgrade2;
		UpgradeButton * golemUpgrade3;
		UpgradeButton * golemUpgrade4;
		UpgradeButton * golemUpgrade5;

		Sprite * levinArrow1;
		Sprite * levinArrow2;
		Sprite * levinArrow3;
		Sprite * levinArrow4;
		Sprite * stoneArrow1;
		Sprite * stoneArrow2;
		Sprite * stoneArrow3;
		Sprite * stoneArrow4;
		Sprite * iceArrow1;
		Sprite * iceArrow2;
		Sprite * iceArrow3;
		Sprite * iceArrow4;
		Sprite * fireArrow1;
		Sprite * fireArrow2;
		Sprite * fireArrow3;
		Sprite * fireArrow4;
		Sprite * airArrow1;
		Sprite * airArrow2;
		Sprite * airArrow3;
		Sprite * airArrow4;
		Sprite * icemanArrow1;
		Sprite * icemanArrow2;
		Sprite * icemanArrow3;
		Sprite * icemanArrow4;
		Sprite * golemArrow1;
		Sprite * golemArrow2;
		Sprite * golemArrow3;
		Sprite * golemArrow4;

		Upgrades_mc();
	};
	struct HintUpgrade_mc : public MovieClip
	{
		HintUpgrade_mc();
		UpgradeButton * myTarget;
	};
	class Upgrades : public Screen
	{
	public:
		//Object tempObject;
		//Object tempObject1;
		Upgrades_mc * container;
		LevelsMenu * levelsMenu;
		UpgradeButton * nowUpgradeButton;
		HintUpgrade_mc* hint;
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

		void enterFrameHandler(float dt);
		bool preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType);
		void mouseMoveHandler(cocos2d::EventMouse * event);

		void mouseDownHandler(cocos2d::EventMouse * event);

		void mouseUpHandler(cocos2d::EventMouse * event);

		void upgradeUpdate();

		void close();

		void kill();

		//void reInit(event:Event);

	};
}
#endif
