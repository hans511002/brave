#ifndef SCREENS_ACHIEVEMENTS_H
#define SCREENS_ACHIEVEMENTS_H
#include "Screen.h"   

namespace screens
{

	struct ContAchieve :public MovieClipSub
	{
		MovieClipSub *  icon;
		MCText * nameTXT;
		MCText * noteTXT;
		ContAchieve(MC *mc, const std::string &  slot, const string &  defAniName = "");
	};
	struct Achievements_mc : public MovieClip
	{
		Back_mc *  back;
		MovieClipSub *  cont;
		MCCase *  shadow;
		MCCase *  contFire1Case;
		MCCase *  contFire2Case;
		MCCase *  contFire3Case;
		MCCase *  contFire4Case;
		MCCase *  contFire5Case;
		MovieClipSub *  contFire1;
		MovieClipSub *  contFire2;
		MovieClipSub *  contFire3;
		MovieClipSub *  contFire4;
		MovieClipSub *  contFire5;
		MovieClipSub *  contBtnClose;
		MCCase *  contBtnCloseCloseCase;

		MovieClipSub *  contBtnBack;
		MovieClipSub *  contBtnForward;
		MCCase * 	contBtnBackArrowCase;
		MCCase * 	contBtnForwardArrowCase;
		ContAchieve *  contAchieve1;
		ContAchieve *  contAchieve2;
		ContAchieve *  contAchieve3;
		ContAchieve *  contAchieve4;
		ContAchieve *  contAchieve5;
		ContAchieve *  contAchieve6;
		ContAchieve *  contAchieve7;
		ContAchieve *  contAchieve8;
		ContAchieve *  contAchieve9;
		ContAchieve *  contAchieve10;
		Achievements_mc();
	};
	class Achievements : public Screen
	{
	public:
		//public var tempObject:Object;
		Achievements_mc * container;

		int  page;
		int fireFrame;

		Achievements();

		virtual bool init();
		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * event);

		virtual void mouseDownHandler(cocos2d::EventMouse * event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		virtual void pageManage(int param1);

		virtual void autoguidersButtons();

		virtual void close();

		virtual void kill();

	};
}
#endif
