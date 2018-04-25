#ifndef ENGINE_WC_H
#define ENGINE_WC_H

#include "cocos2d.h"
#include "JsonUtil.h"
#include "dragonBones/cocos2dx/CCDragonBonesHeaders.h"
#include "dragonbones/DragonBonesHeaders.h"
#include "BaseNode.h"

namespace engine
{
    class World;
    struct MovieClip:public BaseNode
    {
		Vec2 myPoint;
		short myFrame;
        dragonBones::CCArmatureDisplay * container;
        int currentFrame;
		string defAniName;
        int totalFrames;
        float speedX;
         
        MovieClip(  dragonBones::CCArmatureDisplay * cont, string defAniName = "");
        MovieClip(string rootPath, string armName, string defAniName = "");

        MovieClip(): container(NULL),currentFrame(0),totalFrames(0),speedX(0) {};
		int getTotalFrames(string aniName = "");
		void gotoAndStop(int cf, string aniName = "");
        void nextFram();
        void update();
		void play(string aniName = "");
		void stop(string aniName = "");
    };
    struct ImageMovieClip :public BaseNode
    {
        int currentFrame; 
        int totalFrames;
        byte playing;
        BaseSprite * cont;
        string filePre;
        ImageMovieClip(string rootPath, string fileNamePre, int imgSize=0);
        int getTotalFrames(string aniName = "");
        void gotoAndStop(int cf, string aniName = "");
        void nextFram();
        void update();
        void play(string aniName = "");
        void stop(string aniName = "");
        void scheduleUpdate(float dt);
        void onEnter();

    };
    struct SpriteClip :public BaseNode
    {
    public:
        BaseSprite * container;  
        SpriteClip(BaseSprite * cont);
    };
    
    //增加删除事件
    struct OnceMovieClip:public MovieClip
    { 
        World * world;

		OnceMovieClip(World * world, dragonBones::CCArmatureDisplay * cont, string defAniName="");
		OnceMovieClip(World * world, string rootPath, string aniName, string defAniName = "");
        void OnceMovieClip::onceMovieHandler(cocos2d::EventCustom *event);
    };
    struct AnimUpgrade_mc :public BaseNode
    {
        dragonBones::CCArmatureDisplay * cont;
    };
    
    //struct AnimUpgrade_mc :public BaseNode
    //{
    //    dragonBones::CCArmatureDisplay * cont;
    //};
}

#endif

