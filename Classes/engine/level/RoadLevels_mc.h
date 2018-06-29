#ifndef ENGINE_LVEL_ROADS_H
#define ENGINE_LVEL_ROADS_H
#include "BaseHeaders.h"

namespace engine{
	
	struct Sector
	{
	    float x,y;
	    float w,h;
		inline Sector(){};
	    inline Sector(float x,float y,float w,float h)
	    {
	        this->x=x;
	        this->y=y;
	        this->w=w;
	        this->h=h;
	    }
	};
	class RoadLevels_mc : public BaseNode{
	public:
		Vec2 initPos;
		int level;
		Common::Array<Sector> sectors;
        Common::Array<BaseNode *> segments;
        
		RoadLevels_mc(int level);
		virtual bool init();
		
		virtual void calcSectors(Common::Array<cocos2d::Point> & path1,Common::Array<cocos2d::Point> & path2,Common::Array<cocos2d::Point> & path3);
        virtual void calcSectors(Common::Array<Sector> &res,Common::Array<cocos2d::Point> & path1,double r);
        virtual void comPathSectors(Common::Array<Sector> &res,Common::Array<Sector> sect1, Common::Array<Sector> sect2, Common::Array<Sector> sect3, double roadWidth);
	};
 
}
#endif
