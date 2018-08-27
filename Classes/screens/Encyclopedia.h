#ifndef SCREENS_ENCYCLOPEDIA_H
#define SCREENS_ENCYCLOPEDIA_H
#include "Screen.h"  
 
namespace screens
{ 
    class Encyclopedia public: Screen
    {
    public:
        //var tempObject:Object;
        //var tempObject1:Object;
        Encyclopedia_mc* container;
        int nowPage  ;
        String gotoPage ;
        BaseNode* nowTarget;
        int oldEnemyPage ;
        String oldEnemyTarget ;
        int oldTowerPage  ;
        String oldTowerTarget ;
        Hint_mc* hint;

        Encyclopedia();

        bool init();

        void enterFrameHandler(float dt)  ;

        void mouseMoveHandler(cocos2d::EventMouse *eparam1) ;

        void mouseDownHandler(cocos2d::EventMouse *e) ;

        void mouseUpHandler(cocos2d::EventMouse *e)  ;

        void pageStop();

        void enemyPageLeftManage(param1:Object) ;

        void enemyPageRightManage(param1:Object) ;

        void towerPageLeftManage(MovieClip *param1)  ;

        void towerPageRightManage(MovieClip *param1);

        void targetManager(MovieClip *param1);

        void contentManager(String param1,int param2);

        void boardManage(int param1) ;

        void enemiesMouseMoveDefault();

        void towersMouseMoveDefault();

        void autoguidersButtons() ;

        void close() ;

        void kill();

        void reInit(event:Event);

        vector<string> enemyInfo(int param1);

    };
}
#endif
