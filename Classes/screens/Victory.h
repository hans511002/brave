#ifndef SCREENS_VICTORY_H 
#define SCREENS_VICTORY_H
#include "BaseHeaders.h"   
#include "Screen.h"

namespace screens
{
    struct SponsorLink:public MovieClipSub
    {
        MovieClipSub * firstSponsorLink1Cont;
        MCCase * firstSponsorLink1Link1Case;
        SponsorLink(MC * mc,const & string slotName,int reinit);
    };
    struct WinMenuBase:public MovieClip
    {
        MovieClipSub * first;
        MovieClipSub * firstStars;
        MovieClipSub * firstScrollBtnContinue;
        MovieClipSub * firstScrollBtnContinueArrow;
        MCCase * firstScrollBtnContinueContinueCase;
        MovieClipSub * firstScrollBtnRestart;
        MovieClipSub * firstScrollBtnRestartArrow;
        MCCase * firstScrollBtnRestartRestartCase; 
        
        MovieClipSub * firstSponsor;
        SponsorLink * firstSponsorLink1;
        SponsorLink * firstSponsorLink2;
        SponsorLink * firstSponsorLink3;
        WinMenuBase(const string & name);
    };
    struct WinMenu_mc:public WinMenuBase
    { 
        WinMenu_mc();
    };
    struct WinMenuFinish_mc:public WinMenuBase
    {
        WinMenuFinish_mc();
    };
    struct WinSurvMenu_mc:public WinMenuBase
    {
        WinSurvMenu_mc();
    };
	class Victory :public Screen
	{
	public:
		MovieClip container;
		int starsFlag;
		World * world;
		bool firstSoundPlay;

		Victory();
		virtual bool init();
		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * event);

		virtual void mouseDownHandler(cocos2d::EventMouse * event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		//virtual void link1Play(event:VideoEvent);

		//virtual void link2Play(event:VideoEvent);

		//virtual void link3Play(event:VideoEvent);

		virtual void removeLinksListeners();


	};
}
#endif
