#ifndef ENGINE_LVEL_LEVEL1_H
#define ENGINE_LVEL_LEVEL1_H
#include "BaseHeaders.h"

#include "Level.h"
namespace engine{
	class Level1_mc : public Level{
	public:
		  
		MovieClipSub * decoration;
        MovieClipSub * decoration1;
        BaseNode * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		MovieClip * place1;
		MovieClip * place2;
		MovieClip * place3;
		MovieClip * place4;
		MovieClip * place5;
		MovieClip * pointer1;

		
		Level1_mc();
		
	};
 
}
#endif

