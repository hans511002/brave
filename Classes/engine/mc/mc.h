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
    struct MCText;
    struct MCCase;
    struct MovieClipSubBase;
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
		static MovieClip * getMc(MC * mc);

        ui::Text * createText(string slot);
        MovieClipSub * createMovieClipSub(string slot);
        MCCase * createCase(string slot, bool draw = true);
        //BaseNode * createCase(string slot, bool draw = false);

        Common::Array<MCText*> mct;
        Common::Array<MCCase*> mcase;
        virtual void addMCbs(MovieClipSubBase * mcs);
        virtual void remove(MovieClipSubBase * ms);
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
        //Common::Array<MCText*> mct;
        //Common::Array<MCCase*> mcase;

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
        virtual void remove(MovieClipSub * ms);

        //virtual void addMCbs(MovieClipSubBase * mcs);
        //virtual void remove(MovieClipSubBase * ms);
        //virtual void destroy(MCText * & mcs);
        //virtual void destroy(MCCase * & mcs);

		virtual void destroy();
		//增加删除事件
		inline bool setOnceMove(World * world);
		virtual void onEnter();
		virtual void onExit();
		virtual void onceMovieHandler(cocos2d::EventCustom *event);
        virtual void gotoAndStop(int cf, string aniName = "");

	};
    struct MovieClipSubBase
    {
        MC * mc;
        dragonBones::Slot * slot;
        Node * display;
        string slotName;
        inline virtual void reinit(){};
        inline MovieClipSubBase() :mc(0), slot(0), display(0){};
        //inline MovieClip * getMc() { return MC::getMc(mc); };
        void addMCbs(MC * mc, MovieClipSubBase * mcs);
    };
    struct MovieClipSub :public virtual MC, MovieClipSubBase
	{
        dragonBones::Armature* arm;
		MovieClipSub(MC *mc, dragonBones::Slot * slot, string defAniName = "");
        MovieClipSub(MC *mc, string slot, string defAniName = "");
		virtual dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
		void setVisible(bool v);
		bool isVisible();
        inline void reinit();
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
        virtual void gotoAndStop(int cf, string aniName = "");
    };

    struct MCText :public ui::Text, MovieClipSubBase
	{
		MCText(MC * mc, string slotName);
        virtual void reinit();
	};
    struct MCCase :public BaseNode, MovieClipSubBase
    {
        bool _draw;
        MCCase(MC * mc, string slotName, bool draw = false);
        virtual void reinit();
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

#define MC_STRUCT(clsName) inline  clsName(dragonBones::CCArmatureDisplay * cont, string defAniName = ""):MovieClip(cont,defAniName){};\
    inline  clsName(string rootPath, string armName, string dbName, string defAniName = "") :MovieClip(rootPath, armName, dbName, defAniName){}; \
    inline  clsName(World * world, string rootPath, string armName, string dbName, string defAniName = "") :MovieClip(world, rootPath, armName, dbName, defAniName){}; \
    inline  clsName(string armName, string dbName, BaseNode *node = NULL) :MovieClip(armName, dbName, node){};

#define MCSUB_STRUCT(clsName) inline clsName(MC *_mc, string soltName, string defAniName = "") :MovieClipSub(_mc, soltName, defAniName){};\
    inline clsName(MC *_mc, dragonBones::Slot * slot, string defAniName = "") :MovieClipSub(_mc, slot, defAniName){};

}

#endif

