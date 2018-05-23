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
	struct MovieClip;
	struct MovieClipSub;
	struct MC
	{
        int currentFrame;
		string defAniName;
        int totalFrames;
		virtual int getTotalFrames(string aniName = "");
		virtual void gotoAndStop(int cf, string aniName = "");
		virtual  void nextFram();
		virtual void update();
        virtual void play(string aniName = "", int times = 1);
		virtual void play(int times);
        virtual void stop(string aniName = "");
		virtual	dragonBones::Armature *getArmature() = 0;
		virtual dragonBones::Animation *getAnimation()   = 0;
		MC();
		void addMcs(MC * mc, MovieClipSub * mcs);
		MovieClip * getMc(MC * mc);

	};
	struct MovieClip :public virtual BaseNode, public virtual MC
    {
        World * world;
		Vec2 myPoint;
		short myFrame;
        float speedX;
        bool isOnce;
        dragonBones::CCArmatureDisplay * container;
		//std::map<std::string, MovieClipSub*> mcs;
		Common::Array<MovieClipSub*> mcs;

		MovieClip(dragonBones::CCArmatureDisplay * cont, string defAniName = "");
        MovieClip(string rootPath, string armName,string dbName, string defAniName = "");
        MovieClip(World * world,string rootPath, string armName,string dbName, string defAniName = "");
        MovieClip(string armName,string dbName,BaseNode *node=NULL);
		virtual	dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
		MovieClip() :container(NULL){};
		virtual bool init();
		virtual void setName(string name);
		void addMcs(MovieClipSub * mcs);
		virtual void destroy(MovieClipSub * & mcs);
		virtual void destroy();
		//����ɾ���¼�
		inline bool setOnceMove(World * world);
		virtual void onEnter();
		virtual void onExit();
		virtual void onceMovieHandler(cocos2d::EventCustom *event);

        ui::Text * createText(string slot);
        MovieClipSub * createMovieClipSub(string slot);
		BaseNode * createCase(string slot, bool draw = false);
	};
	struct MovieClipSub :public virtual MC
	{
		MC *mc;
		dragonBones::Slot * slot;
		dragonBones::Armature* arm;
		MovieClipSub(MC *mc, dragonBones::Slot * slot, string defAniName = "");
		MovieClipSub(MC *mc, string solt, string defAniName = "");
		virtual dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
		inline MovieClip * getMc() { return MC::getMc(mc); };
		void setVisible(bool v);
		void isVisible();
		void reinit();
		cocos2d::Point getPosition();
		float getPositionX();
		float getPositionY();
		void setPosition(cocos2d::Point pos);
		void setPosition(float x,float y);
		void setPositionX(float x);
		void setPositionY(float y);
		Size getContentSize();
		Node* getDisplayNode();
		inline float getScale() { return getDisplayNode()->getScale(); };
		inline float getScaleX() { return getDisplayNode()->getScaleX(); };
		inline float getScaleY() { return getDisplayNode()->getScaleY(); };

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
     
    struct AnimUpgrade_mc :public MovieClip
    {
         
    };
    
    //struct AnimUpgrade_mc :public BaseNode
    //{
    //    dragonBones::CCArmatureDisplay * cont;
    //};
}

#endif

