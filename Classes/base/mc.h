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
    struct MovieClipSubBase;
	struct MovieClipSub;
    struct MCText;
    struct MCCase;
	struct MCSprite;
	struct MCMask;
	struct MC
	{
        int currentFrame;
		string defAniName;
        int totalFrames;
		string type;
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

		MCText * createText(string slot);
        MovieClipSub * createMovieClipSub(string slot);
		MovieClip * createMovieClip(string slot,string rootPath, string armName, string dbName, string defAniName = "");
		MovieClip * createMovieClip(string slot,string rootPath, string dbName);
		MovieClip * MC::createMovieClip(string slot, MovieClip * mc);
        MCCase * createCase(string slot, bool draw = true);
		MCSprite * createSprite(string slot, string file);
		MCSprite * createSprite(string slot, Sprite* file = NULL);
		MCMask * createMask(string slot);
		

		void addMcs(MC * mc, MovieClipSub * mcs);
		virtual bool remove(MovieClipSub * ms);
		static MovieClip * getMc(MC * mc);

		Common::Array<MovieClipSub*> submc;
		//Common::Array<MCText*> mct;
		Common::Array<MovieClipSubBase *> mcbs;
        virtual void addMCbs(MovieClipSubBase * mcs);
		virtual bool remove(MovieClipSubBase * ms);
	};
    struct MovieClipSubBase 
    {
		bool isReady;
        MC * mc;
        dragonBones::Slot * slot;
        Node * display;
        string slotName;
		bool visible;
		virtual void setVisible(bool v);
        virtual bool reinit() ;
		inline MovieClipSubBase() :isReady(false), mc(0), slot(0), display(0), visible(true){};
        //inline MovieClip * getMc() { return MC::getMc(mc); };
        //void addMCbs(MC * mc, MovieClipSubBase * mcs);
    };
    struct MovieClip :public virtual BaseNode, public virtual MC,public virtual MovieClipSubBase
    {
		string rootPath ;
		string  armName;
		string  dbName;
        World * world;
		Vec2 myPoint;
		short myFrame;
		float speedX;
		float speedY;
        bool isOnce;
        dragonBones::CCArmatureDisplay * cont;
		//std::map<std::string, MovieClipSub*> mcs;
        //Common::Array<MCText*> mct;
        //Common::Array<MCCase*> mcase;

		//所有全部子集群,用于自动删除
		Common::Array<MovieClipSub*> mcs;

		MovieClip(dragonBones::CCArmatureDisplay * cont, string defAniName = "");
        MovieClip(string rootPath, string armName,string dbName, string defAniName = "");
        MovieClip(World * world,string rootPath, string armName,string dbName, string defAniName = "");
        MovieClip(string armName,string dbName,BaseNode *node=NULL);
        
        MovieClip(MC *mc, dragonBones::Slot * slot,string rootPath, string armName,string dbName,string defAniName = "");
        MovieClip(MC *mc, string slot, string rootPath, string armName,string dbName,string defAniName = "");
		MovieClip(MC *mc, string slot, string rootPath, string dbName);

		bool MovieClip::init(string rootPath, string armName, string dbName, string defAniName="");

		virtual	dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
		MovieClip() :world(0), isOnce(0){};//tmp
		virtual bool init();
		virtual void setName(string name);

		virtual void setVisible(bool v);
		virtual bool reinit();

		void addMcs(MovieClipSub * mcs);
        virtual void destroy(MovieClipSub * & mcs);
		virtual bool remove(MovieClipSub * ms);

		inline Vec2 convertToWorldSpace(Vec2 pos) { return BaseNode::convertToWorldSpace(pos); };
		inline Vec2 localToGlobal(Vec2 pos) { return this->convertToWorldSpace(pos); };
		inline Vec2 globalToLocal(Vec2 pos) { return this->convertToNodeSpaceAR(pos); };
		
		virtual float getWidth();
		virtual float getHeight();
		virtual   void setWidth(float w);
		virtual   void setHeight(float h);

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
	
	struct MovieClipSub :public virtual MC, MovieClipSubBase, public   BaseFuns
	{
        dragonBones::Armature* arm;
		MovieClipSub(MC *mc, dragonBones::Slot * slot, string defAniName = "");
        MovieClipSub(MC *mc, string slot, string defAniName = "");
		virtual dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
		virtual void setVisible(bool v);
 
		bool isVisible();
		inline bool reinit();
		cocos2d::Point getPosition();
		float getPositionX();
		float getPositionY();
		void setPosition(cocos2d::Point pos);
		void setPosition(float x,float y);
		void setPositionX(float x);
		void setPositionY(float y);
		Size getContentSize();
		dragonBones::CCArmatureDisplay * container;
		Node* getDisplayNode();
		inline float getScale() { return getDisplayNode()->getScale(); };
		inline float getScaleX() { return getDisplayNode()->getScaleX(); };
		inline float getScaleY() { return getDisplayNode()->getScaleY(); };

		inline void setScaleX(float s) {   getDisplayNode()->setScaleX(s); };
		inline void setScaleY(float s) { getDisplayNode()->setScaleY(s); };
		inline void setScale(float s) { getDisplayNode()->setScale(s); };
		
		inline float getRotation(){ return getDisplayNode()->getRotation(); };
		inline void 	setRotation(float r){return getDisplayNode()->setRotation(r); };

		inline Vec2 convertToWorldSpace(Vec2 pos) { return getDisplayNode()->convertToWorldSpace(pos); };
		inline Vec2 localToGlobal(Vec2 pos) { return getDisplayNode()->convertToWorldSpace(pos); };
		inline Vec2 globalToLocal(Vec2 pos) { return getDisplayNode()->convertToNodeSpaceAR(pos); };
		virtual void gotoAndStop(int cf, string aniName = "");
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(getDisplayNode(), op); };
		inline virtual float getAlpha() { return  BaseNode::getAlpha(getDisplayNode()); };


		virtual float getWidth();
		virtual float getHeight();
		virtual   void setWidth(float w);
		virtual   void setHeight(float h);

	};

#define DEFINE_MCSUB(clzName,member) struct clzName :public MovieClipSub { \
	inline clzName(MC *mc, string solt) :MovieClipSub(mc, slot){}; member };


	struct MCText :public ui::Text, MovieClipSubBase, public   BaseFuns
	{
		MCText(MC * mc, string slotName);
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(this, op); };
		inline virtual float getAlpha() { return  BaseNode::getAlpha(this); };
		virtual void setVisible(bool v);
		virtual bool reinit();
	};
	struct MCCase :public BaseNode, MovieClipSubBase 
    {
        bool _draw;
        MCCase(MC * mc, string slotName, bool draw = false);
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(this, op); };
		inline virtual float getAlpha() {return BaseNode::getAlpha(this); };
		virtual void setVisible(bool v);
		virtual bool reinit();
		inline void stop(){};
	};
	struct MCSprite :public BaseSprite, MovieClipSubBase 
	{
		bool initSprite;
		MCSprite(MC * mc, string slotName, string file);
		MCSprite(MC * mc, string slotName, cocos2d::Sprite * sprite);
		MCSprite(MC * mc, string slotName);
		virtual void setVisible(bool v);
		virtual bool reinit();
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(this, op); };
		inline virtual float getAlpha() { return  BaseNode::getAlpha(this); };
		inline void stop(){};
	};
	struct MCMask :public BaseNode, MovieClipSubBase 
	{
		cocos2d::Sprite * mask;
		MCMask(MC * mc, string slotName);
		virtual void setVisible(bool v);
		virtual bool reinit();
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
         inline AnimUpgrade_mc():MovieClip("tower/","AnimUpgrade_mc","AnimUpgrade_mc"){};
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

