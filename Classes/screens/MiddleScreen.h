#ifndef SCREENS_MIDDLESCREEN_H
#define SCREENS_MIDDLESCREEN_H
#include "BaseHeaders.h"
 

namespace screens
{ 
	struct MiddleScreenCentr_mc :public MovieClip
	{

	};
	 class MiddleScreen_mc :public MovieClip
	{
	public:
		MovieClip * leftDown;
		MovieClip *  leftUp ;
		MovieClip *  rightDown ;
		MovieClip *  rightUp ;

		 MiddleScreen_mc()
		{
			return;
		}// end function

	 };

    class MiddleScreen : public cocos2d::Node
    {
	public:
		int i;// public var i : int;
        //public var tempObject:Object;
		MiddleScreen_mc *container;
		MiddleScreenCentr_mc * middleRound;
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
