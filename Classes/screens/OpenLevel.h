#ifndef SCREENS_OPENLEVEL_H
#define SCREENS_OPENLEVEL_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
#include "base/mc.h"
using namespace engine;

namespace screens
{
    class OpenLevel_mc :public MovieClip
    {
    public:
        MovieClip* back;
        MovieClip* board;
        MovieClip* shadow;

		OpenLevel_mc() :MovieClip("", "","")
        {
            return;
        }// end function

    };
    class HintSurvival_mc :public MovieClip
    {
    public:
        ui::Text * nameTXT;
        ui::Text * noteTXT;

		HintSurvival_mc() :MovieClip("", "","")
        {
            return;
        }// end function

    };
    class OpenLevel :public BaseNode
    {
    public:
        int i;
        //public var tempObject:Object;
        int frameCounter;
        OpenLevel_mc* container;
        int playLevel;
        bool openFlag;// true;
        bool closeFlag;
        int oldComplexity;
        bool dead;
        HintSurvival_mc* hintSurvival;
        //public var openSurvEdu:Training_91_mc;
        int eyes1Counter ;
        //public var loginOrRegisterClass:LoginOrRegister;
        cocos2d::Point autoguidesMouse_pt;
        BaseNode * autoguidesObject;
        cocos2d::Point autoguidesObject_pt;
        float autoguidesObjectWidth;
        float autoguidesObjectHeight;

        OpenLevel(int param1);

        bool init();

        void enterFrameHandler(cocos2d::EventMouse * event) ;

        void mouseMoveHandler(cocos2d::EventMouse * param1) ;

        void mouseDownHandler(cocos2d::EventMouse * event) ;

        void mouseUpHandler(cocos2d::EventMouse * event) ;

        void complexityManage(int param1) ;

        void statusManage(bool param1= false) ;

        void manageListeners(string param1) ;

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
