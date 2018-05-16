#ifndef SCREENS_MIDDLESCREEN_H
#define SCREENS_MIDDLESCREEN_H
#include "BaseHeaders.h"
 

namespace screens
{ 
    
    class MiddleScreen_mc :public MovieClip
	{
	public:
        ImageMovieClip * leftDown;
        ImageMovieClip *  leftUp;
        ImageMovieClip *  rightDown;
        ImageMovieClip *  rightUp;

        MiddleScreen_mc();
        bool init();
         void stop();
	 };

    class MiddleScreen : public cocos2d::Node
    {
	public:
		int i;// public var i : int;
        //public var tempObject:Object;
		MiddleScreen_mc *container;
        MovieClip * middleRound;
		int frameCounter;// public var frameCounter : int = 0;
		int gogoCounter;// public var gogoCounter : int = 0;
		string openScreenName;// public var openScreenName : String;

        MiddleScreen(string param1);

        bool init();
		virtual void onEnter( );
		void MiddleScreen::enterFrameHandler(float dt);


	};
}
#endif
