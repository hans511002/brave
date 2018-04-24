#ifndef ENGINE_CASTS_CASTMASK_MC_H
#define ENGINE_CASTS_CASTMASK_MC_H
#include "BaseHeaders.h"  
 
namespace engine
{
	class World;

	struct CastMask_mc : public MovieClip
	{
		MovieClip * archiveCase;
		MovieClip * castAirCase ;
		MovieClip * castGolemCase ;
		MovieClip * castIcemanCase;
		MovieClip * fireCase ;
		MovieClip * getAllCase ;
		MovieClip * iceCase ;
		MovieClip * interfaceUpCase ;
		MovieClip * levinCase ;
		MovieClip * sellCase ;
		MovieClip * stoneCase;

		CastMask_mc()
		{
			return;
		}// end function

	};

}
#endif
