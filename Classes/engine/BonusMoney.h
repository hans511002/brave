#ifndef ENGINE_BONUSMONEY_H
#define ENGINE_BONUSMONEY_H
#include "BaseHeaders.h" 

namespace engine
{
 
	struct BonusMoney_mc:public MovieClip
	{
	    MovieClipSub * cont;
	    ui::Text * contNoteTXT;
	    BonusMoney_mc();
	};

	class BonusMoney :public BaseNode
	{
	public:
		int i;
		bool dead;
		World * world;
		BonusMoney_mc* container;
		int counter;

		BonusMoney();

		virtual bool init();

		virtual  void update(float dt = 0);

		virtual void kill();

	};
}
#endif 
