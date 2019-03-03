#ifndef SCREENS_PAUSEMENU_H
#define SCREENS_PAUSEMENU_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"



namespace screens
{

	struct PauseMenu_mc : public MovieClip
	{
		MCCase * shadow;
		MovieClipSub * scroll;
		MovieClipSub *scrollBtnSound;
		MCCase *scrollBtnSoundSoundCase;
		MovieClipSub *scrollBtnMusic;
		MCCase * scrollBtnMusicMusicCase;
		MovieClipSub *scrollBtnRestart;
		MovieClipSub *scrollBtnRestartArrow;
		MCCase *scrollBtnRestartRestartCase;
		MovieClipSub *scrollBtnResume;
		MovieClipSub *scrollBtnResumeArrow;
		MCCase *scrollBtnResumeResumeCase;
		MovieClipSub *scrollBtnExit;
		MovieClipSub *scrollBtnExitArrow;
		MCCase *scrollBtnExitExitCase;
		PauseMenu_mc();
	};
	class PauseMenu : public Screen
	{
	public:
		PauseMenu_mc * container;
		World * world;
		int questionFlag;
		float startMusicVolume;

		PauseMenu();

		virtual bool init();

		virtual void enterFrameHandler(float dt);
		virtual bool  preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType);

		virtual void mouseMoveHandler(cocos2d::EventMouse *param1);

		virtual void mouseDownHandler(cocos2d::EventMouse *event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		virtual void close();

		//void reInit(event:Event);

	};
}
#endif
