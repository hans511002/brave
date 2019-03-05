#ifndef SCREENS_VICTORY_H 
#define SCREENS_VICTORY_H
#include "BaseHeaders.h"   
#include "Screen.h"

namespace screens
{
	struct WinMenuBase :public MovieClip
	{
		MovieClipSub * first;
		MovieClipSub * firstStars; 

		MovieClipSub * firstScroll;

		MovieClipSub * firstScrollLogo;
		MCCase * firstScrollLogoLogoCase;

		MovieClipSub * firstScrollBtnContinue;
		MovieClipSub * firstScrollBtnContinueArrow;
		MCCase * firstScrollBtnContinueContinueCase;
		MovieClipSub * firstScrollBtnRestart;
		MovieClipSub * firstScrollBtnRestartArrow;
		MCCase * firstScrollBtnRestartRestartCase;

		MovieClipSub * firstSponsor;
		MovieClipSub * firstSponsorLink1;
		MCCase * firstSponsorLink1Link1Case;
		MovieClipSub * firstSponsorLink2;
		MCCase * firstSponsorLink2Link2Case;
		MovieClipSub * firstSponsorLink3;
		MCCase * firstSponsorLink3Link3Case;

		WinMenuBase(const string & name);
	};
	struct WinMenu_mc :public WinMenuBase
	{
		WinMenu_mc();
	};
	struct WinMenuFinish_mc :public WinMenuBase
	{
		WinMenuFinish_mc();
	};
	struct WinSurvMenu_mc :public WinMenuBase
	{
		WinSurvMenu_mc();
	};
	class Victory :public Screen
	{
	public:
		WinMenuBase* container;
		int starsFlag;
		World * world;
		bool firstSoundPlay;

		Victory();
		virtual bool init();
		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * event);

		virtual void mouseDownHandler(cocos2d::EventMouse * event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		virtual void link1Play(cocos2d::Event *e);

		virtual void link2Play(cocos2d::Event *e);

		virtual void link3Play(cocos2d::Event *e);

		virtual void removeLinksListeners();

	};
}
#endif
