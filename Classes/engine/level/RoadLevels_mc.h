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
	};
 
}
#endif

