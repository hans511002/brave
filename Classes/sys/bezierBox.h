#ifndef BEZIERBOX_H
#define BEZIERBOX_H
//#include "BaseHeaders.h"
#include "cocos2d.h"
#include "common/Common.h" 

namespace sys
{

    class BezierBox
    {
    public:
        bool buildBezier;
        bool viewBezier;
        int i;
        void * tempObject;
		//Common::Array<cocos2d::Point> level1_path1 ;
		Common::Array<cocos2d::Point> level1_path1;
		//float level1_path1[24][2];
        Common::Array<cocos2d::Point> level1_path2;
        Common::Array<cocos2d::Point> level1_path3;
        Common::Array<cocos2d::Point> level2_path1;
        Common::Array<cocos2d::Point> level2_path2;
        Common::Array<cocos2d::Point> level2_path3;
        Common::Array<cocos2d::Point> level3_path1;
        Common::Array<cocos2d::Point> level3_path2;
        Common::Array<cocos2d::Point> level3_path3;
        Common::Array<cocos2d::Point> level3_path11;
        Common::Array<cocos2d::Point> level3_path12;
        Common::Array<cocos2d::Point> level3_path13;
        Common::Array<cocos2d::Point> level4_path1;
        Common::Array<cocos2d::Point> level4_path2;
        Common::Array<cocos2d::Point> level4_path3;
        Common::Array<cocos2d::Point> level4_path11;
        Common::Array<cocos2d::Point> level4_path12;
        Common::Array<cocos2d::Point> level4_path13;
        Common::Array<cocos2d::Point> level5_path1;
        Common::Array<cocos2d::Point> level5_path2;
        Common::Array<cocos2d::Point> level5_path3;
        Common::Array<cocos2d::Point> level5_path11;
        Common::Array<cocos2d::Point> level5_path12;
        Common::Array<cocos2d::Point> level5_path13;
        Common::Array<cocos2d::Point> level6_path1;
        Common::Array<cocos2d::Point> level6_path2;
        Common::Array<cocos2d::Point> level6_path3;
        Common::Array<cocos2d::Point> level6_path11;
        Common::Array<cocos2d::Point> level6_path12;
        Common::Array<cocos2d::Point> level6_path13;
        Common::Array<cocos2d::Point> level7_path1;
        Common::Array<cocos2d::Point> level7_path2;
        Common::Array<cocos2d::Point> level7_path3;
        Common::Array<cocos2d::Point> level8_path1;
        Common::Array<cocos2d::Point> level8_path2;
        Common::Array<cocos2d::Point> level8_path3;
        Common::Array<cocos2d::Point> level8_path11;
        Common::Array<cocos2d::Point> level8_path12;
        Common::Array<cocos2d::Point> level8_path13;
        Common::Array<cocos2d::Point> level9_path1;
        Common::Array<cocos2d::Point> level9_path2;
        Common::Array<cocos2d::Point> level9_path3;
        Common::Array<cocos2d::Point> level9_path11;
        Common::Array<cocos2d::Point> level9_path12;
        Common::Array<cocos2d::Point> level9_path13;
        Common::Array<cocos2d::Point> level10_path1;
        Common::Array<cocos2d::Point> level10_path2;
        Common::Array<cocos2d::Point> level10_path3;
        Common::Array<cocos2d::Point> level10_path11;
        Common::Array<cocos2d::Point> level10_path12;
        Common::Array<cocos2d::Point> level10_path13;
        Common::Array<cocos2d::Point> level11_path1;
        Common::Array<cocos2d::Point> level11_path2;
        Common::Array<cocos2d::Point> level11_path3;
        Common::Array<cocos2d::Point> level11_path11;
        Common::Array<cocos2d::Point> level11_path12;
        Common::Array<cocos2d::Point> level11_path13;
        Common::Array<cocos2d::Point> level12_path1;
        Common::Array<cocos2d::Point> level12_path2;
        Common::Array<cocos2d::Point> level12_path3;
        Common::Array<cocos2d::Point> level12_path11;
        Common::Array<cocos2d::Point> level12_path12;
        Common::Array<cocos2d::Point> level12_path13;
        Common::Array<cocos2d::Point> level13_path1;
        Common::Array<cocos2d::Point> level13_path2;
        Common::Array<cocos2d::Point> level13_path3;
        Common::Array<cocos2d::Point> level13_path11;
        Common::Array<cocos2d::Point> level13_path12;
        Common::Array<cocos2d::Point> level13_path13;
        Common::Array<cocos2d::Point> level14_path1;
        Common::Array<cocos2d::Point> level14_path2;
        Common::Array<cocos2d::Point> level14_path3;
        Common::Array<cocos2d::Point> level14_path11;
        Common::Array<cocos2d::Point> level14_path12;
        Common::Array<cocos2d::Point> level14_path13;
        Common::Array<cocos2d::Point> level15_path1;
        Common::Array<cocos2d::Point> level15_path2;
        Common::Array<cocos2d::Point> level15_path3;
        Common::Array<cocos2d::Point> level15_path11;
        Common::Array<cocos2d::Point> level15_path12;
        Common::Array<cocos2d::Point> level15_path13;
        Common::Array<cocos2d::Point> level15_path21;
        Common::Array<cocos2d::Point> level15_path22;
        Common::Array<cocos2d::Point> level15_path23;

        BezierBox(){}

        void bezierPoints();  

	};
};


#endif