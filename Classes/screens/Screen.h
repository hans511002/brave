#ifndef SCREENS_SCREEN_H
#define SCREENS_SCREEN_H
#include "BaseHeaders.h"   

namespace screens
{   
    class Screen : public BaseNode
    {
    public:
        int i,j;
        int frameCounter;
        bool openFlag;
        bool closeFlag;
        bool dead;
        
        cocos2d::Point autoguidesMouse_pt;
        BaseNode * autoguidesObject;
        cocos2d::Point autoguidesObject_pt;
        float autoguidesObjectWidth;
        float autoguidesObjectHeight;
        Screen();
    };

}
#endif
