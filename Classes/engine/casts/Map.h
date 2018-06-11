#ifndef ENGINE_CASTS_MAP_H
#define ENGINE_CASTS_MAP_H
#include "BaseHeaders.h"

namespace engine{
 
    namespace    casts
    {

        class Map
        {
        public:
            int i, j;
            Common::Array<cocos2d::Point> road1;
            Common::Array<cocos2d::Point> road2;
            Common::Array<cocos2d::Point> road3;
            Common::Array<cocos2d::Point> allPointsRoad1;
            Common::Array<cocos2d::Point> allPointsRoad2;
            Common::Array<cocos2d::Point> allPointsRoad3;

            Map();

            void mapLevel1();

            void mapLevel2();

            void mapLevel3();

            void mapLevel4();

            void mapLevel5();

            void  mapLevel6();

            void  mapLevel7();

            void  mapLevel8();

            void  mapLevel9();

            void  mapLevel10();

            void  mapLevel11();

            void  mapLevel12();

            void  mapLevel13();

            void  mapLevel14();

            void  mapLevel15();

        };
    }
}
#endif

