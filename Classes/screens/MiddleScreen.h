#ifndef SCREENS_MIDDLESCREEN_H
#define SCREENS_MIDDLESCREEN_H
#include "Screen.h"
 

namespace screens
{ 
    
    struct MiddleScreen_mc :public MovieClip
	{
        MovieClipSub * leftDown;
        MovieClipSub * leftUp;
        MovieClipSub * rightDown;
        MovieClipSub * rightUp; 
        MiddleScreen_mc(); 
		virtual	void stop();

	 };

    struct MiddleScreenCentr_mc:public MovieClip
    {
		MiddleScreenCentr_mc();
	};
    class MiddleScreen : public BaseNode
    {
	public:
		int i;// public var i : int;
        //public var tempObject:Object;
		MiddleScreen_mc *container;
        MovieClip * middleRound;
		int frameCounter;// public var frameCounter : int = 0;
		int gogoCounter;// public var gogoCounter : int = 0;
		string openScreenName;// public var openScreenName : String;

        MiddleScreen(const string &  param1);

        virtual bool init();
		virtual void onEnter( );
        virtual void enterFrameHandler(float dt);


	};
}
#endif
