#ifndef SCREENS_FASTPAUSE_H
#define SCREENS_FASTPAUSE_H
#include "BaseHeaders.h" 

using namespace engine;

namespace screens
{
    struct FastPause_mc : public MovieClip
    {
        FastPause_mc();
    };
    
    class FastPause :public BaseNode
    {
    public:
        bool dead;
        FastPause_mc *container;
        bool openFlag   ;
        bool closeFlag;
        World * world;
        float startMusicVolume;
        int frameCounter;

        FastPause():openFlag(true),closeFlag(false),startMusicVolume(0),frameCounter(0);

        bool init();

        void enterFrameHandler(float dt) ;

        void mouseClickHandler(cocos2d::EventMouse * event);

        void kill();

        //void reInit(event:Event) 
        //{
        //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //    this->removeEventListener(MouseEvent.CLICK, this->mouseClickHandler);
        //    if (Sounds.instance.musicChanel)
        //    {
        //        Sounds.instance.musicChanel.soundTransform = new SoundTransform(this->startMusicVolume, 0);
        //    }
        //    if (this->world->getSphere || this->world->cast)
        //    {
        //        this->world->manageMouse("hide");
        //    }
        //    return;
        //}// end function

    }
}
#endif
