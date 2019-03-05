#ifndef SCREENS_STARTLOGO_H 
#define SCREENS_STARTLOGO_H
#include "BaseHeaders.h"   
#include "Screen.h"

namespace screens
{ 
    struct StartLogo_mc:public MovieClip
    {
        StartLogo_mc();
    };
    class StartLogo : public Screen
    {
    public: 
        StartLogo_mc * container;
        //public var nowSound:Sound;
        //public var nowSoundTransform:SoundTransform;

        StartLogo();

        bool init();

        void enterFrameHandler(float dt);
   };
}
#endif
