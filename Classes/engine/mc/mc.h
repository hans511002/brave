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
        World * world;
		Vec2 myPoint;
		short myFrame;
        dragonBones::CCArmatureDisplay * container;
        int currentFrame;
        int totalFrames;
        float speedX;

        MovieClip(World * world, dragonBones::CCArmatureDisplay * cont, int totalFrames);
        MovieClip(World * world,string rootPath, string aniName ,int totalFrames) ;
        MovieClip():world(NULL),container(NULL),currentFrame(0),totalFrames(0),speedX(0) {};
        void gotoAndStop(int cf);
        void nextFram();
        void update();
		void play();
		void stop();
    };
    struct SpriteClip :public BaseNode
    {
    public:
        BaseSprite * container;  
        SpriteClip(BaseSprite * cont);
    };
    
    //����ɾ���¼�
    struct OnceMovieClip:public MovieClip
    { 
        OnceMovieClip(World * world,dragonBones::CCArmatureDisplay * cont,int totalFrames) ;
        OnceMovieClip(World * world,string rootPath, string aniName ,int totalFrames) ;
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

