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
		//string type;
        virtual int getTotalFrames(const string &  aniName = "");
        virtual void gotoAndStop(int cf, const string &  aniName = "");
		virtual  void nextFram();
        virtual void play(const string &  aniName = "", int times = 1);
		virtual void play(int times);
        virtual void stop(const string &  aniName = "");
		virtual	dragonBones::Armature *getArmature() = 0;
		virtual dragonBones::Animation *getAnimation()   = 0;
		MC();

        MCText * createText(const string &  slot);
        MovieClipSub * createMovieClipSub(const string &  slot);
        MovieClip * createMovieClip(const string &  slot, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "");
        MovieClip * createMovieClip(const string &  slot, const string &  rootPath, const string &  dbName);
        MovieClip * MC::createMovieClip(const string &  slot, MovieClip * mc);
		MCCase * createCase(const string &  slot, bool mouseEnabled=true, bool draw = true);
        MCSprite * createSprite(const string &  slot, const string &  file);
        MCSprite * createSprite(const string &  slot, Sprite* file);
        MCMask * createMask(const string &  slot);
        Sprite *getSprite(const string &  slotName);
		

		void addMcs(MC * mc, MovieClipSub * mcs);
		virtual bool remove(MovieClipSub * ms);
		static MovieClip * getRootMc(MC * mc);

		Common::Array<MovieClipSub*> submc;
		//Common::Array<MCText*> mct;
		Common::Array<MovieClipSubBase *> submcbs;
        virtual void addMCbs(MovieClipSubBase * mcs);
		virtual bool remove(MovieClipSubBase * ms);

        virtual Node * getMemNode(const string &  slotName);
        MovieClipSub*  getMemSubMC(const string &  slotName);
        template<typename T = Node> T * getMem(const string &  slotName) { return ISTYPE(T, getMemNode(slotName)); };
	};
    struct MovieClipSubBase 
    {
		bool isReady;
        MC * mc;
        dragonBones::Slot * slot;
		dragonBones::Bone * bone;
		dragonBones::Bone * root;
        Node * display;
		Vec2 disPos;
        string slotName;
		bool visible;
		virtual void setVisible(bool v);
        virtual bool reinit() ;
		inline MovieClipSubBase() :isReady(false), mc(0), slot(NULL), bone(NULL), display(0), visible(true){};
		template<typename T = MC> T * getParentMC() { return ISTYPE(T, mc); };
        //inline MovieClip * getRootMc() { return MC::getRootMc(mc); };
        //void addMCbs(MC * mc, MovieClipSubBase * mcs);
		virtual Vec2 getDisPosition();
		virtual Vec2 getDisArPos();
		void MovieClipSubBase::setDisScale();
		virtual void initPos();
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
        dragonBones::CCArmatureDisplay * container;
		//std::map<std::string, MovieClipSub*> mcs;
        //Common::Array<MCText*> mct;
        //Common::Array<MCCase*> mcase;

		//所有全部子集群,用于自动删除
		Common::Array<MovieClipSub*> mcs;
		Common::Array<MovieClipSubBase*> mcbs;
        
        MovieClip(dragonBones::CCArmatureDisplay * container, const string &  defAniName = "");
        MovieClip(const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "");
        MovieClip(World * world, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "");
        MovieClip(const string &  armName, const string &  dbName, BaseNode *node = NULL);
        
        MovieClip(MC *mc, dragonBones::Slot * slot, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "");
        MovieClip(MC *mc, const string &  slot, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "");
        MovieClip(MC *mc, const string &  slot, const string &  rootPath, const string &  dbName);

        bool MovieClip::init(const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "");

		virtual	dragonBones::Armature *getArmature();
		virtual dragonBones::Animation *getAnimation();
		MovieClip() :world(0), isOnce(0){};//tmp
		virtual bool init();
        virtual void setName(const string &  name);

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
		virtual   void resetSize();

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
        virtual void gotoAndStop(int cf, const string &  aniName = "");

        virtual void update(float dt = 0);
		virtual const dragonBones::Rectangle & getRectangle();
		virtual void changeAnchorPoint(float xy);
		virtual  void drawRange();
	};
	
	struct MovieClipSub :public virtual MC, MovieClipSubBase, public   EventNode
	{
		cocos2d::Mat4 transform;
		bool setTrans;

		string name;
		void * userData;
        dragonBones::Armature* arm;
        MovieClipSub(MC *mc, dragonBones::Slot * slot, const string &  defAniName = "");
        MovieClipSub(MC *mc, const string &  slot, const string &  defAniName = "");
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
        virtual void gotoAndStop(int cf, const string &  aniName = "");
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(getDisplayNode(), op); };
		inline virtual float getAlpha() { return  BaseNode::getAlpha(getDisplayNode()); };
		inline virtual string getName() { return getDisplayNode()->getName(); };

		virtual float getWidth();
		virtual float getHeight();
		virtual   void setWidth(float w);
		virtual   void setHeight(float h);

		void setUserData(void * data) { this->userData = data; };
		void* getUserData() { return this->userData; };
        virtual void update(float dt = 0);
		virtual void setName(string name){ this->name = name; };
	};

#define DEFINE_MCSUB(clzName,member) struct clzName :public MovieClipSub { \
	inline clzName(MC *mc, string solt) :MovieClipSub(mc, slot){}; member };


	struct MCText :public ui::Text, MovieClipSubBase, public   EventNode
	{
        MCText(MC * mc, const string &  slotName);
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(this, op); };
		inline virtual float getAlpha() { return  BaseNode::getAlpha(this); };
		virtual void setVisible(bool v);
		virtual bool reinit();
	};
	struct MCCase :public BaseNode, MovieClipSubBase 
    {
        bool _draw;
		MCCase(MC * mc, const string &  slotName, bool mouseEnabled=true, bool draw = false);
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(this, op); };
		inline virtual float getAlpha() {return BaseNode::getAlpha(this); };
		virtual void setVisible(bool v);
		virtual bool reinit();
		inline void stop(){};
	};
	struct MCSprite :public BaseSprite, MovieClipSubBase 
	{
		bool initSprite;
        MCSprite(MC * mc, const string &  slotName, const string &  file);
        MCSprite(MC * mc, const string &  slotName, cocos2d::Sprite * sprite);
        MCSprite(MC * mc, const string &  slotName);
		virtual void setVisible(bool v);
		virtual bool reinit();
		inline virtual void setAlpha(float op) { BaseNode::setAlpha(this, op); };
		inline virtual float getAlpha() { return  BaseNode::getAlpha(this); };
		inline void stop(){};
	};
	struct MCMask :public BaseNode, MovieClipSubBase 
	{
		cocos2d::Sprite * mask;
        MCMask(MC * mc, const string &  slotName);
        virtual bool reinit();
        virtual void setVisible(bool v);
        virtual bool isVisible() { if(mask)return mask->isVisible(); return false; };
        inline virtual void setAlpha(float op) { BaseNode::setAlpha(mask, op); };
        inline virtual float getAlpha() { return  BaseNode::getAlpha(mask); };
        inline float getScale() {   if(mask)return mask->getScale(); return 1; };
        inline float getScaleX() {   if(mask) return mask->getScaleX(); return 1; };
        inline float getScaleY() { if(mask) return mask->getScaleY(); return 1; };

        inline void setScaleX(float s) { if(mask)   mask->setScaleX(s); };
        inline void setScaleY(float s) { if(mask)   mask->setScaleY(s); };
        inline void setScale(float s) { if(mask)   mask->setScale(s); };

        inline float getRotation() { if(mask)return mask->getRotation(); return 0; };
        inline void  setRotation(float r) { if(mask)  mask->setRotation(r); };

	};

	struct ImageMovieClip :public BaseNode
    {
        int currentFrame; 
        int totalFrames;
        byte playing;
        BaseSprite * container;
        string filePre;
        char numFormat[8];
        ImageMovieClip(const string &  rootPath, const string &  fileNamePre, int numFormat, int imgSize = 0);
        int getTotalFrames(const string &  aniName = "");
        void gotoAndStop(int cf, const string &  aniName = "");
        void nextFram();
        virtual void update(float dt=0);
        void play(const string &  aniName = "");
        void stop(const string &  aniName = "");
        void scheduleUpdate(float dt);
        void onEnter();

    };
    struct SpriteClip :public BaseNode
    {
    public:
        BaseSprite * container;  
        SpriteClip(BaseSprite * container);
    };
     
    struct AnimUpgrade_mc :public MovieClip
    {
         inline AnimUpgrade_mc():MovieClip("tower/","AnimUpgrade_mc","AnimUpgrade_mc"){
			 setNodeType("AnimUpgrade_mc");
		 };
    };

    //struct AnimUpgrade_mc :public BaseNode
    //{
    //    dragonBones::CCArmatureDisplay * container;
    //};

#define MC_STRUCT(clsName) inline  clsName(dragonBones::CCArmatureDisplay * container, string defAniName = ""):MovieClip(container,defAniName){};\
    inline  clsName(string rootPath, string armName, string dbName, string defAniName = "") :MovieClip(rootPath, armName, dbName, defAniName){}; \
    inline  clsName(World * world, string rootPath, string armName, string dbName, string defAniName = "") :MovieClip(world, rootPath, armName, dbName, defAniName){}; \
    inline  clsName(string armName, string dbName, BaseNode *node = NULL) :MovieClip(armName, dbName, node){};

#define MCSUB_STRUCT(clsName) inline clsName(MC *_mc, string soltName, string defAniName = "") :MovieClipSub(_mc, soltName, defAniName){};\
    inline clsName(MC *_mc, dragonBones::Slot * slot, string defAniName = "") :MovieClipSub(_mc, slot, defAniName){};

}

#endif

