#ifndef SCREENS_MIDDLESCREEN_H
#define SCREENS_MIDDLESCREEN_H
#include "BaseHeaders.h"
 

namespace screens
{ 
    class MiddleScreen : public cocos2d::Node
    {
	public:
		int i;// public var i : int;
        //public var tempObject:Object;
        //public var container:MiddleScreen_mc;
        //public var middleRound:MiddleScreenCentr_mc;
		int frameCounter;// public var frameCounter : int = 0;
		int gogoCounter;// public var gogoCounter : int = 0;
		string openScreenName;// public var openScreenName : String;

        MiddleScreen(string param1);

        bool init();
        void enterFrameHandler(cocos2d::Event* event);

	};
}
#endif
