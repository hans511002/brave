#ifndef SCREENS_STARTMENU_H
#define SCREENS_STARTMENU_H
#include "Screen.h"   


namespace screens
{
	struct StartMenu_mc : public MovieClip
	{ 
		MovieClipSub * start;
		MCCase * startStartCase;
		MovieClipSub * credits;
		MCCase * creditsCreditsCase;
		MovieClipSub * btnMusic;
		MCCase * btnMusicMusicCase;
		MovieClipSub * btnSound;
		MCCase * btnSoundSoundCase;
		MovieClipSub * back;
		MCCase * backBackCase;
		MovieClipSub * saveType;
		MovieClipSub * saveTypeLocalSave;
		MCCase * saveTypeLocalSaveLocalSaveCase;
		MovieClipSub * saveTypeOnlineSave;
		MCCase * saveTypeOnlineSaveOnlineSaveCase;
		MCText * saveTypeOnlineSaveNickTXT;
		MCText * saveTypeOnlineSaveWelcomeTXT;
		MCSprite * saveTypeOnlineSaveLogo;
		MovieClipSub * glitter;

		MovieClipSub * question;
		MCText * questionNoteTXT;	 
		MovieClipSub * questionBtnYes;
		MCCase * questionBtnYesYesCase;
		MovieClipSub * questionBtnNo;
		MCCase * questionBtnNoNoCase;
	 
		MCCase * comlogo;
		MCText * copyright;
		MCText * tips;

		MovieClipSub * game1;
		MCCase * game1Game1Case;
		MCCase * game1NewGame1Case;
		MovieClipSub * game1SyncSlot;
		MCCase * game1SyncSlotSyncSlotCase;
		MovieClipSub * game1DeleteSlot;
		MCCase * game1DeleteSlotDeleteSlotCase;
		MCText * game1NumTXT; 
		MovieClipSub * game2;
		MCCase * game2Game2Case;
		MCCase * game2NewGame2Case;
		MovieClipSub * game2SyncSlot;
		MCCase * game2SyncSlotSyncSlotCase;
		MovieClipSub * game2DeleteSlot;
		MCCase * game2DeleteSlotDeleteSlotCase;
		MCText * game2NumTXT;
		MovieClipSub * game3;
		MCCase * game3Game3Case;
		MCCase * game3NewGame3Case;
		MovieClipSub * game3SyncSlot;
		MCCase * game3SyncSlotSyncSlotCase;
		MovieClipSub * game3DeleteSlot;
		MCCase * game3DeleteSlotDeleteSlotCase;
		MCText * game3NumTXT;
		StartMenu_mc();
	};

	class StartMenu : public Screen
	{
	public:
		//public var tempObject:Object;
		StartMenu_mc * container;
		bool firstPlay;
		int page;
		int question;
		//Credits* creditsClass;
		bool loginFlag;
		int loginFlag1;
		string welcomeText, nickText;
		int waitCounter;
		int syncLoginCounter;
		Hint_mc * syncHint;
		bool firstMusicPlay;

		float mouseX, mouseY;

		StartMenu();
		virtual bool init();

		virtual void enterFrameHandler(float dt);
		virtual bool preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType);

		virtual void mouseMoveHandler(cocos2d::EventMouse * param1);

		virtual void mouseDownHandler(cocos2d::EventMouse * event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		virtual void autoguidersButtons(); 

		//void reInit(event:Event);

	};
}
#endif
