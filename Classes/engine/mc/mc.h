#ifndef ENGINE_WC_H
#define ENGINE_WC_H

#include "cocos2d.h"
#include "JsonUtil.h"
#include "dragonbones/cocos2d/DBCCRenderHeaders.h"
#include "dragonbones/DragonBonesHeaders.h"

namespace engine
{
    class World;
    struct MovieClip:public BaseNode
    {
        World * world;
        dragonBones::DBCCArmatureNode * container;
        int currentFrame;
        int totalFrames;
        MovieClip(World * world,dragonBones::DBCCArmatureNode * cont,int totalFrames) ;
        MovieClip(World * world,string rootPath, string aniName ,int totalFrames) ;
        void gotoAndStop(int cf);
        void nextFram();
        void update();
        void stop(); 
    };
    struct SpriteClip :public BaseNode
    {
    public:
        BaseSprite * container;  
        BaseSprite(BaseSprite * cont) ;
    };
    
    //����ɾ���¼�
    struct OnceMovieClip:public MovieClip
    { 
        OnceMovieClip(World * world,dragonBones::DBCCArmatureNode * cont,int totalFrames) ;
        OnceMovieClip(World * world,string rootPath, string aniName ,int totalFrames) ;
 

        void OnceMovieClip::onceMovieHandler(cocos2d::EventCustom *event);
    };
    struct AnimUpgrade_mc :public BaseNode
    {
        dragonBones::DBCCArmatureNode * cont;
    };
    
    //struct AnimUpgrade_mc :public BaseNode
    //{
    //    dragonBones::DBCCArmatureNode * cont;
    //};
}

#endif

