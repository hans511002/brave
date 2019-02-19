#ifndef SCREENS_OPENLEVEL_H
#define SCREENS_OPENLEVEL_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
#include "base/mc.h"
using namespace engine;
#include "Screen.h"

namespace screens
{
	class OpenLevel_mc :public MovieClip
	{
	public:
		Back_mc * back;
		MovieClipSub* board;
		MCCase * shadow;
		MovieClipSub* boardInfoAdd;
		MovieClipSub* boardInfoAddLevinSphere;
		MovieClipSub* boardInfoAddStoneSphere;
		MovieClipSub* boardInfoAddIceSphere;
		MovieClipSub* boardInfoAddFireSphere;

		MCCase* boardInfoAddLevinSphereSphereCase;
		MCCase* boardInfoAddStoneSphereSphereCase;
		MCCase* boardInfoAddIceSphereSphereCase;
		MCCase* boardInfoAddFireSphereSphereCase;
		
		MovieClipSub* boardInfoAddGetSphere;

		MovieClipSub* boardCurrentComplexity;
		MCCase* boardCurrentComplexityComplexityCase;
		MovieClipSub* boardCurrentComplexityFire;

		MovieClipSub* boardStatus;
		MCText * boardHeaderTXT;
		MovieClipSub* boardStar1;
		MovieClipSub* boardStar2;
		MovieClipSub* boardStar3;
		MovieClipSub* boardWreath;
		MovieClipSub* boardMainMode;
		MCCase* boardMainModeMainModeCase;
		MovieClipSub* boardSurvivalMode;
		MCCase* boardSurvivalModeSurvivalModeCase;
		MovieClipSub* boardSurvivalModeEyes;

		MovieClipSub* boardMap;
		MovieClipSub* boardStart;
		MCCase* 	boardStartStartCase;
		MovieClipSub* boardDescription;
		

		OpenLevel_mc();

	};
	class HintSurvival_mc :public MovieClip
	{
	public:
		//ui::Text * nameTXT;
		//ui::Text * noteTXT;

		HintSurvival_mc();
	};
	class OpenLevel :public Screen
	{
	public:
		//public var tempObject:Object;
		OpenLevel_mc* container;
		int playLevel;
		int oldComplexity;
		HintSurvival_mc* hintSurvival;
		//public var openSurvEdu:Training_91_mc;
		int eyes1Counter;
		//public var loginOrRegisterClass:LoginOrRegister;
	 

		OpenLevel(int param1);

		bool init();

		void enterFrameHandler(cocos2d::EventMouse * event);

		void mouseMoveHandler(cocos2d::EventMouse * param1);

		void mouseDownHandler(cocos2d::EventMouse * event);

		void mouseUpHandler(cocos2d::EventMouse * event);

		void complexityManage(int param1);

		void statusManage(bool param1 = false);

		void manageListeners(string param1);

		void autoguidersButtons();

		void close();

		void kill();

		//public function reInit(event:Event) : void
		//{
		//    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		//    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
		//    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
		//    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
		//    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
		//    this->stage.frameRate = 30;
		//    return;
		//}// end function

	};
}
#endif
