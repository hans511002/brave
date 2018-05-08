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
	struct MC
	{
        int currentFrame;
		string defAniName;
        int totalFrames;
		virtual int getTotalFrames(string aniName = "");
		virtual void gotoAndStop(int cf, string aniName = "");
		virtual  void nextFram();
		virtual void update();
		virtual void play(string aniName = "");
		virtual void stop(string aniName = "");
		virtual	dragonBones::Armature *getArmature() = 0;
		virtual dragonBones::Animation *getAnimation()   = 0;
		MC();
	};
	struct MovieClip :public virtual BaseNode, public virtual MC
    {
		Vec2 myPoint;
		short myFrame;
        float speedX;
        dragonBones::CCArmatureDisplay * container;
		MovieClip(dragonBones::CCArmatureDisplay * cont, string defAniName = "");
        MovieClip(string rootPath, string armName, string defAniName = "");
		virtual	dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
		MovieClip() :container(NULL){};
	};
	struct MovieClipSub :public virtual MC
	{
		dragonBones::Armature* arm;
		MovieClipSub(dragonBones::Armature * cont, string defAniName = "");
		virtual dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
	};
	struct ImageMovieClip :public BaseNode
    {
        int currentFrame; 
        int totalFrames;
        byte playing;
        BaseSprite * cont;
        string filePre;
        char numFormat[8];
        ImageMovieClip(string rootPath, string fileNamePre,int numFormat, int imgSize=0);
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

